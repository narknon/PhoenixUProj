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

#include "AkToolBehavior.h"

#include "AkUnrealHelper.h"
#include "AkEventBasedToolBehavior.h"
#include "AkLegacyToolBehavior.h"

DEFINE_LOG_CATEGORY_STATIC(LogAudiokineticToolBehavior, Log, All);

AkToolBehavior* AkToolBehavior::s_Instance = nullptr;

AkToolBehavior* AkToolBehavior::Get()
{
	if (!s_Instance)
	{
		if (AkUnrealHelper::IsUsingEventBased())
		{
			s_Instance = new AkEventBasedToolBehavior;
		}
		else
		{
			s_Instance = new AkLegacyToolBehavior;
		}
	}

	return s_Instance;
}

void AkToolBehavior::ForceEventBasedToolBehavior()
{
	delete s_Instance;
	s_Instance = new AkEventBasedToolBehavior;
}

bool AkToolBehavior::AkAssetManagementManager_ModifyProjectSettings(FString& ProjectContent)
{
	static const TArray<PropertyToChange> PropertiesToAdd = {
		{ TEXT("GenerateMultipleBanks"), TEXT("True"), TEXT("<Property Name=\"GenerateMultipleBanks\" Type=\"bool\" Value=\"True\"/>") },
		{ TEXT("GenerateSoundBankJSON"), TEXT("True"), TEXT("<Property Name=\"GenerateSoundBankJSON\" Type=\"bool\" Value=\"True\"/>") },
		{ TEXT("SoundBankGenerateEstimatedDuration"), TEXT("True"), TEXT("<Property Name=\"SoundBankGenerateEstimatedDuration\" Type=\"bool\" Value=\"True\"/>") },
		{ TEXT("SoundBankGenerateMaxAttenuationInfo"), TEXT("True"), TEXT("<Property Name=\"SoundBankGenerateMaxAttenuationInfo\" Type=\"bool\" Value=\"True\"/>") },
		{ TEXT("SoundBankGeneratePrintGUID"), TEXT("True"), TEXT("<Property Name=\"SoundBankGeneratePrintGUID\" Type=\"bool\" Value=\"True\"/>") },
	};

	return InsertProperties(PropertiesToAdd, ProjectContent);
}

bool AkToolBehavior::InsertProperties(const TArray<PropertyToChange>& PropertiesToChange, FString& ProjectContent)
{
	static const auto PropertyListStart = TEXT("<PropertyList>");
	static const FString EndTag = TEXT(">");
	static const TCHAR EmptyElementEndChar = '/';
	static const FString ValueTag = TEXT("<Value>");
	static const FString EndValueTag = TEXT("</Value>");

	static const FString ValueAttribute = TEXT("Value=\"");
	static const FString EndValueAttribute = TEXT("\"");

	bool modified = false;

	int32 propertyListPosition = ProjectContent.Find(PropertyListStart);
	if (propertyListPosition != -1)
	{
		int32 insertPosition = propertyListPosition + FCString::Strlen(PropertyListStart);

		for (auto itemToAdd : PropertiesToChange)
		{
			auto idx = ProjectContent.Find(itemToAdd.Name);
			if (idx == -1)
			{
				ProjectContent.InsertAt(insertPosition, FString::Printf(TEXT("\n\t\t\t\t%s"), *itemToAdd.Xml));
				modified = true;
			}
			else
			{
				FString ValueText;
				FString EndValueText;
				int32 EndTagIdx = ProjectContent.Find(EndTag, ESearchCase::IgnoreCase, ESearchDir::FromStart, idx);
				if (ProjectContent[EndTagIdx - 1] == EmptyElementEndChar)
				{
					// The property is an empty element, the value will be in an attribute
					ValueText = ValueAttribute;
					EndValueText = EndValueAttribute;
				}
				else
				{
					// We are in a ValueList
					ValueText = ValueTag;
					EndValueText = EndValueTag;
				}

				int32 ValueIdx = ProjectContent.Find(ValueText, ESearchCase::IgnoreCase, ESearchDir::FromStart, idx);
				int32 EndValueIdx = ProjectContent.Find(EndValueText, ESearchCase::IgnoreCase, ESearchDir::FromStart, ValueIdx);
				if (ValueIdx != -1 && ValueIdx > idx && ValueIdx < EndValueIdx)
				{
					ValueIdx += ValueText.Len();
					auto ValueEndIdx = ProjectContent.Find(EndValueText, ESearchCase::IgnoreCase, ESearchDir::FromStart, ValueIdx);
					if (ValueEndIdx != -1)
					{
						FString value = ProjectContent.Mid(ValueIdx, ValueEndIdx - ValueIdx);
						if (value != itemToAdd.Value)
						{
							ProjectContent.RemoveAt(ValueIdx, ValueEndIdx - ValueIdx, false);
							ProjectContent.InsertAt(ValueIdx, itemToAdd.Value);
							modified = true;
						}
					}
				}
				else
				{
					UE_LOG(LogAudiokineticToolBehavior, Log, TEXT("Could not change value for %s in Wwise project. Some features might not work properly."), *itemToAdd.Name);
				}
			}
		}
	}

	return modified;
}
