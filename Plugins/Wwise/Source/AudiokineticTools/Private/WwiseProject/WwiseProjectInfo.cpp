/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/

#include "WwiseProjectInfo.h"

#include "AkSettings.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"
#include "XmlFile.h"
#include "Internationalization/Regex.h"
#include "Misc/FileHelper.h"

#include <AK/Tools/Common/AkFNVHash.h>

DEFINE_LOG_CATEGORY_STATIC(LogWwiseProjectParser, Log, All);

void WwiseProjectInfo::Parse()
{
	SupportedPlatforms.Empty();
	SupportedLanguages.Empty();
	DefaultLanguage.Empty();
	CacheDirectory.Empty();

	FString ProjectPath = GetProjectPath();
	if (ProjectPath.Len() > 0)
	{
		FText errorMessage;
		int32 errorLineNumber;
		FString ProjectFileString;

		if (!FFileHelper::LoadFileToString(ProjectFileString, *ProjectPath))
		{
			UE_LOG(LogWwiseProjectParser, Error, TEXT("Could not read the Wwise project file '<%s>'."), *ProjectPath);
			return;
		}

		ParseCacheDirectory(*ProjectFileString);
		SanitizeProjectFileString(ProjectFileString);
		FFastXml::ParseXmlFile(this, nullptr, ProjectFileString.GetCharArray().GetData(), nullptr, false, false, errorMessage, errorLineNumber);

		if (DefaultLanguage.Len() == 0 || DefaultLanguage == TEXT(""))
		{
			DefaultLanguage = TEXT("English(US)");
		}
	}
}

void WwiseProjectInfo::ParseCacheDirectory(const FString ProjectFileString)
{
	FString PatternString(TEXT("<MiscSettingEntry Name=\"Cache\">([\\s\\S]*?)</MiscSettingEntry>"));
	FRegexPattern Pattern(PatternString);
	FRegexMatcher Matcher(Pattern, ProjectFileString);
	if (Matcher.FindNext())
	{
		CacheDirectory = Matcher.GetCaptureGroup(1);
		CacheDirectory.RemoveFromStart(TEXT("<![CDATA["));
		CacheDirectory.RemoveFromEnd(TEXT("]]>"));
	}
	else if (CacheDirectory.IsEmpty())
	{
		CacheDirectory = TEXT(".cache");
		UE_LOG(LogWwiseProjectParser, Log, TEXT("Could not parse the Cache directory from the Wwise project file. Using default value : .cache"));
	}

	if (FPaths::IsRelative(CacheDirectory))
	{
		CacheDirectory = FPaths::ConvertRelativePathToFull(FPaths::GetPath(GetProjectPath()), CacheDirectory);
	}
}

void WwiseProjectInfo::SanitizeProjectFileString(FString& InOutProjectFileString)
{
	FString PatternString(TEXT("<\\!\\[CDATA[\\s\\S]*?>"));
	FRegexPattern Pattern(PatternString);
	FRegexMatcher Matcher(Pattern, InOutProjectFileString);
	while (Matcher.FindNext())
	{
		InOutProjectFileString = InOutProjectFileString.Replace(*Matcher.GetCaptureGroup(0), TEXT(""));
	}
}

bool WwiseProjectInfo::ProcessAttribute(const TCHAR* AttributeName, const TCHAR* AttributeValue)
{
	if (bInsidePlatformElement)
	{
		if (FCString::Strcmp(AttributeName, TEXT("Name")) == 0)
		{
			CurrentPlatformInfo.Name = AttributeValue;
		}
		else if (FCString::Strcmp(AttributeName, TEXT("ID")) == 0)
		{
			FGuid::ParseExact(AttributeValue, EGuidFormats::DigitsWithHyphensInBraces, CurrentPlatformInfo.ID);
		}
	}

	if (bInsideLanguageElement)
	{
		if (FCString::Strcmp(AttributeName, TEXT("Name")) == 0)
		{
			if (FCString::Strcmp(AttributeValue, TEXT("External")) == 0
				|| FCString::Strcmp(AttributeValue, TEXT("Mixed")) == 0
				|| FCString::Strcmp(AttributeValue, TEXT("SFX")) == 0)
			{
				bInsideLanguageElement = false;
			}
			else
			{
				if (CurrentLanguageInfo.Name.IsEmpty())
				{
					CurrentLanguageInfo.Name = AttributeValue;

					AK::FNVHash32 hash;
					FTCHARToUTF8 utf8(*CurrentLanguageInfo.Name.ToLower());
					CurrentLanguageInfo.ShortID = hash.Compute(utf8.Get(), utf8.Length());
				}
			}
		}
		else if (FCString::Strcmp(AttributeName, TEXT("ID")) == 0)
		{
			FGuid::ParseExact(AttributeValue, EGuidFormats::DigitsWithHyphensInBraces, CurrentLanguageInfo.ID);
		}
	}

	if (bInsidePropertyElement
		&& FCString::Strcmp(AttributeName, TEXT("Name")) == 0
		&& FCString::Strcmp(AttributeValue, TEXT("DefaultLanguage")) == 0
		)
	{
		bInsideDefaultLanguage = true;
	}

	if (bInsideDefaultLanguage && FCString::Strcmp(AttributeName, TEXT("Value")) == 0)
	{
		DefaultLanguage = AttributeValue;
		bInsideDefaultLanguage = false;
	}

	return true;
}

bool WwiseProjectInfo::ProcessClose(const TCHAR* Element)
{
	if (bInsidePlatformElement && FCString::Strcmp(Element, TEXT("Platform")) == 0)
	{
		SupportedPlatforms.Add(CurrentPlatformInfo);
		bInsidePlatformElement = false;
	}
	if (bInsideLanguageElement && FCString::Strcmp(Element, TEXT("Language")) == 0)
	{
		SupportedLanguages.Add(CurrentLanguageInfo);
		bInsideLanguageElement = false;
	}
	if (bInsidePropertyElement && FCString::Strcmp(Element, TEXT("Property")) == 0)
	{
		bInsidePropertyElement = false;
	}
	return true;
}

bool WwiseProjectInfo::ProcessComment(const TCHAR* Comment)
{
	return true;
}

bool WwiseProjectInfo::ProcessElement(const TCHAR* ElementName, const TCHAR* ElementData, int32 XmlFileLineNumber)
{
	if (FCString::Strcmp(ElementName, TEXT("Platform")) == 0)
	{
		bInsidePlatformElement = true;

		// Clear CurrentPlatformInfo
		new (&CurrentPlatformInfo) FWwisePlatformInfo();
	}
	else if (FCString::Strcmp(ElementName, TEXT("Language")) == 0)
	{
		bInsideLanguageElement = true;

		// Clear CurrentLanguageInfo
		new (&CurrentLanguageInfo) FWwiseLanguageInfo();
	}
	else if (FCString::Strcmp(ElementName, TEXT("Property")) == 0)
	{
		bInsidePropertyElement = true;
	}

	if (bInsideDefaultLanguage && FCString::Strcmp(ElementName, TEXT("Value")) == 0)
	{
		// Only use this as a backup
		if (DefaultLanguage.IsEmpty())
		{
			DefaultLanguage = ElementData;
		}
		bInsideDefaultLanguage = false;
	}

	return true;
}

bool WwiseProjectInfo::ProcessXmlDeclaration(const TCHAR* ElementData, int32 XmlFileLineNumber)
{
	return true;
}

FString WwiseProjectInfo::GetProjectPath() const
{
	FString ProjectPath;

	if (const UAkSettings* Settings = GetDefault<UAkSettings>())
	{
		ProjectPath = Settings->WwiseProjectPath.FilePath;

		if (FPaths::IsRelative(ProjectPath))
		{
			ProjectPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir(), ProjectPath);
		}
	}

	return ProjectPath;
}