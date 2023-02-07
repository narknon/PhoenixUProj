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

#include "WwiseProjectParser.h"
#include "WorkUnitXmlVisitor.h"


WwiseProjectParser::WwiseProjectParser(WorkUnitXmlVisitor* vis)
{
	visitor = vis;
	inWorkUnit = false;
	inPhysicalFolder = false;
}

bool WwiseProjectParser::ProcessXmlDeclaration(const TCHAR* ElementData, int32 XmlFileLineNumber) 
{
	return true;
};

bool WwiseProjectParser::ProcessElement(const TCHAR* ElementName, const TCHAR* ElementData, int32 XmlFileLineNumber) 
{
	if (FString(ElementName) == TEXT("PhysicalFolder"))
	{
		inPhysicalFolder = true;
		currentPhysicalPath = ElementData;
	}
	else if (FString(ElementName) == TEXT("WorkUnit"))
	{
		inWorkUnit = true;
	}
	return true;
};

bool WwiseProjectParser::ProcessAttribute(const TCHAR* AttributeName, const TCHAR* AttributeValue) 
{
	if (inWorkUnit)
	{
		if (FString(AttributeName) == TEXT("Name"))
		{
			workUnitName = FString(AttributeValue);
		}
		else if (FString(AttributeName) == TEXT("ID"))
		{
			TArray<FString> splitPaths;
			currentPhysicalPath.ParseIntoArray(splitPaths, TEXT("\\"), true);
			if (EWwiseItemType::PhysicalFoldersToIgnore.Contains(splitPaths[0]))
			{
				return true;
			}
			FGuid::ParseExact(FString(AttributeValue), EGuidFormats::DigitsWithHyphensInBraces, currentId);
		}
	}
	else if (inPhysicalFolder)
	{
		if (FString(AttributeName) == TEXT("Path"))
		{
			currentPhysicalPath = FString(AttributeValue);
		}
	}

	return true;
}

bool WwiseProjectParser::ProcessClose(const TCHAR* ElementName) 
{
	if (FString(ElementName) == TEXT("PhysicalFolder"))
	{
		inPhysicalFolder = false;
		currentPhysicalPath.Empty();
	}
	else if (FString(ElementName) == TEXT("WorkUnit"))
	{
		TArray<FString> splitPaths;
		currentPhysicalPath.ParseIntoArray(splitPaths, TEXT("\\"), true);
		if (!EWwiseItemType::PhysicalFoldersToIgnore.Contains(splitPaths[0]) && 
			currentId.IsValid() && !workUnitName.IsEmpty() && !currentPhysicalPath.IsEmpty())
		{
			visitor->EnterFolderOrBus(currentId, workUnitName, currentPhysicalPath.Replace(TEXT("\\"), TEXT("/")), EWwiseItemType::PhysicalFolder);
		}
		currentId = FGuid();
		workUnitName.Empty();
		inWorkUnit = false;

	}
	return true;
}

bool WwiseProjectParser::ProcessComment(const TCHAR* Comment) 
{
	return true;
}