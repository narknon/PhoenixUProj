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

#include "WwiseWorkUnitParser.h"

#include "Misc/Paths.h"
#include "Misc/ScopedSlowTask.h"
#include "HAL/FileManager.h"
#include "XmlFile.h"
#include "AkUnrealHelper.h"
#include "WorkUnitXmlVisitor.h"
#include "AssetManagement/AkAssetDatabase.h"
#include "Misc/FileHelper.h"
#include "Internationalization/Regex.h"
#include "WwiseProjectParser.h"
#include "WwiseProjectInfo.h"
#if UE_5_0_OR_LATER
#include "HAL/PlatformFileManager.h"
#else
#include "HAL/PlatformFilemanager.h"
#endif

#define LOCTEXT_NAMESPACE "AkAudio"

DEFINE_LOG_CATEGORY_STATIC(LogWwiseWorkUnitParser, Log, All);

bool WwiseWorkUnitParser::Parse()
{
	if (!Visitor)
	{
		return false;
	}

	auto projectFilePath = AkUnrealHelper::GetWwiseProjectPath();

	if (!FPaths::FileExists(projectFilePath))
	{
		return false;
	}

	Visitor->OnBeginParse();
	ParsePhysicalFolders(); 
	projectRootFolder = FPaths::GetPath(projectFilePath) + TEXT("/");
	for (int i = EWwiseItemType::Event; i <= EWwiseItemType::LastWwiseDraggable; ++i)
	{
		const auto CurrentType = static_cast<EWwiseItemType::Type>(i);
		Visitor->Init(CurrentType);
		parseFolders(EWwiseItemType::FolderNames[i], CurrentType);
	}
	Visitor->End();

	return true;
}

bool WwiseWorkUnitParser::ForceParse()
{
	if (!Visitor)
	{
		return false;
	}

	wwuLastPopulateTime.Reset();
	Visitor->ForceInit();
	return Parse();
}

void WwiseWorkUnitParser::ParsePhysicalFolders()
{
	FScopedSlowTask SlowTask(2.f, LOCTEXT("AK_PopulatingPickerPhysicalFolders", "Parsing Wwise Physical Folders..."));
	SlowTask.MakeDialog();
	Visitor->OnBeginPhysicalFolderParse();
	FString ProjectFilePath = AkUnrealHelper::GetWwiseProjectPath();
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*ProjectFilePath))
	{
		UE_LOG(LogWwiseWorkUnitParser, Error, TEXT("Could not find the project file '<%s>' while syncing assets. Some folders may not appear in the content browser or in the Wwise picker."), *ProjectFilePath);
		return;
	}

	FString ProjectFileString;
	if (!FFileHelper::LoadFileToString(ProjectFileString, *ProjectFilePath))
	{
		UE_LOG(LogWwiseWorkUnitParser, Error, TEXT("Could not read the project file '<%s>' while syncing assets. Some folders may not appear in the content browser or in the Wwise picker."), *ProjectFilePath);
		return;
	}

	//replace CDATA elements in xml so they don't kill the parser
	WwiseProjectInfo::SanitizeProjectFileString(ProjectFileString);
	WwiseProjectParser Parser(Visitor);
	FText ErrorOut;
	int32 ErrorLineNumber;
	FFastXml::ParseXmlFile(&Parser, nullptr, ProjectFileString.GetCharArray().GetData(), nullptr, false, false, ErrorOut,  ErrorLineNumber);
	if (!ErrorOut.IsEmpty())
	{
		UE_LOG(LogWwiseWorkUnitParser, Error, TEXT("Failed to parse the project file '<%s>' while syncing assets. Some folders may not appear in the content browser or in the Wwise picker. \n Line <%i> - Error message: <%s>."), *ProjectFilePath, ErrorLineNumber, *ErrorOut.ToString());
	}
	else 
	{
		Visitor->EndPhysicalFolderParse();
	}
}

void WwiseWorkUnitParser::parseFolders(const FString& FolderName, EWwiseItemType::Type ItemType)
{
	TArray<FString> NewWwus;
	TArray<FString> KnownWwus;
	TArray<FString> WwusToProcess;
	TArray<FString> WwusToRemove;
	FString FullPath = FPaths::Combine(projectRootFolder, FolderName);

	IFileManager::Get().FindFilesRecursive(NewWwus, *FullPath, TEXT("*.wwu"), true, false);

	TMap<FString, FDateTime>& LastPopTimeMap = wwuLastPopulateTime.FindOrAdd(ItemType);
	LastPopTimeMap.GetKeys(KnownWwus);

	// Get lists of files to parse, and files that have been deleted
	NewWwus.Sort();
	KnownWwus.Sort();
	int32 iKnown = 0;
	int32 iNew = 0;

	while (iNew < NewWwus.Num() && iKnown < KnownWwus.Num())
	{
		if (KnownWwus[iKnown] == NewWwus[iNew])
		{
			// File was there and is still there.  Check the FileTimes.
			FDateTime LastPopTime = LastPopTimeMap[KnownWwus[iKnown]];
			FDateTime LastModifiedTime = IFileManager::Get().GetTimeStamp(*NewWwus[iNew]);
			if (LastPopTime < LastModifiedTime)
			{
				WwusToProcess.Add(KnownWwus[iKnown]);
			}
			iKnown++;
			iNew++;
		}
		else if (KnownWwus[iKnown] > NewWwus[iNew])
		{
			// New Wwu detected. Add it to the ToProcess list
			WwusToProcess.Add(NewWwus[iNew]);
			iNew++;
		}
		else
		{
			// A file was deleted. Can't process it now, it would change the array indices.
			WwusToRemove.Add(KnownWwus[iKnown]);
			iKnown++;
		}
	}

	//The remainder from the files found on disk are all new files.
	for (; iNew < NewWwus.Num(); iNew++)
	{
		WwusToProcess.Add(NewWwus[iNew]);
	}

	//All the remainder is deleted.
	while (iKnown < KnownWwus.Num())
	{
		Visitor->RemoveWorkUnit(KnownWwus[iKnown]);
		LastPopTimeMap.Remove(KnownWwus[iKnown]);
		iKnown++;
	}

	//Delete those tagged.
	for (FString& ToRemove : WwusToRemove)
	{
		Visitor->RemoveWorkUnit(ToRemove);
		LastPopTimeMap.Remove(ToRemove);
	}

	FScopedSlowTask SlowTask(WwusToProcess.Num(), LOCTEXT("AK_PopulatingPicker", "Parsing Wwise Work Unit..."));
	SlowTask.MakeDialog();

	preParseWorkUnits(WwusToProcess, ItemType);

	for(auto wwuItem : standaloneWwusToParse) 
	{
		auto info = wwuItem.Value;
		parseWorkUnitFile(info, getRelativePath(info, ItemType), ItemType, &SlowTask);
	}

	TArray<FGuid>keyCopy;
	nestedWwusToParse.GetKeys(keyCopy);

	//Parse nested work units in correct order
	for (int i=0; i < keyCopy.Num();)
	{
		auto currentWwuGuid = keyCopy[i];
		//skip if already parsed through recursion
		if (!nestedWwusToParse.Contains(currentWwuGuid)) {
			i++;
			continue;
		}

		auto wwuInfo = nestedWwusToParse[currentWwuGuid];
		//parse parent first
		if (nestedWwusToParse.Contains(wwuInfo.parentWorkUnitGuid))
		{
			keyCopy.Swap(i, keyCopy.IndexOfByKey(wwuInfo.parentWorkUnitGuid));
			continue;
		}

		parseWorkUnitFile(wwuInfo, getRelativePath(wwuInfo, ItemType), ItemType, &SlowTask);
		i++;
	}
}

void WwiseWorkUnitParser::preParseWorkUnits(const TArray<FString>& WwusToProcess, EWwiseItemType::Type ItemType)
{
	parsedWwus.Empty();
	nestedWwusToParse.Empty();
	standaloneWwusToParse.Empty();
	unparseableWwus.Empty();

	for (int i = 0; i < WwusToProcess.Num(); i++)
	{
		auto workUnitPath = WwusToProcess[i];
		FXmlFile workUnitXml(workUnitPath);
		if (!workUnitXml.IsValid()) 
		{
			unparseableWwus.Add(workUnitPath);
			Visitor->RegisterError(workUnitPath, workUnitXml.GetLastError());
		}
		auto workUnitInfo = peekWorkUnit(workUnitPath, ItemType);
		if (workUnitInfo.successfullyParsed)
		{
			if (workUnitInfo.isStandalone) {
				standaloneWwusToParse.Add(workUnitInfo.wwuGuid, workUnitInfo);
			}
			else
			{
				nestedWwusToParse.Add(workUnitInfo.wwuGuid, workUnitInfo);
			}
		}
		else 
		{
			Visitor->RegisterError(workUnitInfo.wwuPath, TEXT("XML was valid, but did not have the expected structure."));
		}
	}
}

FString WwiseWorkUnitParser::getRelativePath(const WorkUnitInfo& info, EWwiseItemType::Type ItemType)
{
	FString relativePath;
	if (info.isStandalone) 
	{
		relativePath = info.wwuPath;
		relativePath.RemoveFromStart(projectRootFolder);
		relativePath.RemoveFromEnd(TEXT(".wwu"));
	}
	else
	{
		auto parentPath = Visitor->FindRelativePath(info.wwuPath, info.parentWorkUnitGuid, ItemType);
		relativePath = FString::Format(TEXT("{0}/{1}"), { parentPath, info.wwuName });
	}
	return relativePath;
}

void WwiseWorkUnitParser::parseWorkUnitFile(const WorkUnitInfo& wwuInfo, const FString& RelativePath, EWwiseItemType::Type ItemType, FScopedSlowTask* SlowTask)
{
	if (SlowTask) 
	{
		FString Message = TEXT("Parsing WorkUnit: ") + FPaths::GetCleanFilename(wwuInfo.wwuName);
		SlowTask->EnterProgressFrame(1.0f, FText::FromString(Message));
	}

	FDateTime LastModifiedTime = IFileManager::Get().GetTimeStamp(*wwuInfo.wwuPath);
	
	Visitor->EnterWorkUnit(wwuInfo, RelativePath, ItemType);	
	if (parseWorkUnitXml(wwuInfo.wwuPath, RelativePath, ItemType)) 
	{
		FDateTime& Time = wwuLastPopulateTime.FindOrAdd(ItemType).FindOrAdd(wwuInfo.wwuPath);
	    Time = LastModifiedTime;
	}
	else
	{
		Visitor->RegisterError(wwuInfo.wwuPath, TEXT("XML was valid, but did not have the expected structure."));
	}
	Visitor->ExitWorkUnit(wwuInfo.isStandalone);
}

WwiseWorkUnitParser::WorkUnitInfo WwiseWorkUnitParser::peekWorkUnit(const FString& WwuFilePath, EWwiseItemType::Type ItemType)
{
	bool isStandalone = false;
	bool successfullyParsed = false;
	FGuid guid;
	FString name;
	FGuid parentGuid;
	FXmlFile Wwu(WwuFilePath);
	if (Wwu.IsValid())
	{
		const FXmlNode* RootNode = Wwu.GetRootNode();
		if (RootNode)
		{
			const FXmlNode* EventsNode = RootNode->FindChildNode(EWwiseItemType::DisplayNames[ItemType]);
			if (EventsNode)
			{
				successfullyParsed = true;
				const FXmlNode* WorkUnitNode = EventsNode->FindChildNode(TEXT("WorkUnit"));
				if (WorkUnitNode)
				{
					successfullyParsed = true;
					FString WorkUnitPersistMode = WorkUnitNode->GetAttribute(TEXT("PersistMode"));
					if (WorkUnitPersistMode == TEXT("Standalone"))
					{
						isStandalone = true;
					}
					name = WorkUnitNode->GetAttribute(TEXT("Name"));
					FGuid::ParseExact(WorkUnitNode->GetAttribute(TEXT("ID")), EGuidFormats::DigitsWithHyphensInBraces, guid);
					auto parentIDString = WorkUnitNode->GetAttribute(TEXT("OwnerID"));
					if (!parentIDString.IsEmpty())
					{
						FGuid::ParseExact(parentIDString, EGuidFormats::DigitsWithHyphensInBraces, parentGuid);
					}
				}
			}
		}
	}
	return { successfullyParsed, isStandalone,  name, WwuFilePath, guid, parentGuid };
}

bool WwiseWorkUnitParser::parseWorkUnitXml( const FString& WorkUnitPath, const FString& RelativePath, EWwiseItemType::Type ItemType)
{
	FXmlFile WorkUnitXml(WorkUnitPath);
	if (!WorkUnitXml.IsValid())
	{
		return false;
	}

	const FXmlNode* RootNode = WorkUnitXml.GetRootNode();
	if (!RootNode)
	{
		return false;
	}

	const FXmlNode* ItemNode = RootNode->FindChildNode(EWwiseItemType::DisplayNames[ItemType]);
	if (!ItemNode)
	{
		return false;
	}

	const FXmlNode* WorkUnitNode = ItemNode->FindChildNode(TEXT("WorkUnit"));
	if (!WorkUnitNode || (WorkUnitNode->GetAttribute(TEXT("Name")) != FPaths::GetBaseFilename(WorkUnitPath)))
	{
		return false;
	}
	FGuid CurrentId;
	FGuid::ParseExact(WorkUnitNode->GetAttribute(TEXT("ID")), EGuidFormats::DigitsWithHyphensInBraces, CurrentId);

	const FXmlNode* CurrentNode = WorkUnitNode->FindChildNode(TEXT("ChildrenList"));
	if (!CurrentNode)
	{
		return true;
	}

	CurrentNode = CurrentNode->GetFirstChildNode();
	if (!CurrentNode)
	{
		return true;
	}

	parseWorkUnitChildren(CurrentNode, WorkUnitPath, RelativePath, ItemType, CurrentId);
	return true;
}

void WwiseWorkUnitParser::recurse(const FXmlNode* CurrentNode, const FString& WorkUnitPath, const FString& CurrentPath, EWwiseItemType::Type ItemType, const FGuid& ParentId)
{
	if (const FXmlNode* ChildrenNode = CurrentNode->FindChildNode(TEXT("ChildrenList")))
	{
		if (const FXmlNode* FirstChildNode = ChildrenNode->GetFirstChildNode())
		{
			parseWorkUnitChildren(FirstChildNode, WorkUnitPath, CurrentPath, ItemType, ParentId);
		}
	}
}

void WwiseWorkUnitParser::parseWorkUnitChildren(const FXmlNode* NodeToParse, const FString& WorkUnitPath, const FString& RelativePath, EWwiseItemType::Type ItemType, const FGuid& ParentId)
{
	for (const FXmlNode* CurrentNode = NodeToParse; CurrentNode; CurrentNode = CurrentNode->GetNextNode())
	{
		FString CurrentTag = CurrentNode->GetTag();
		FString CurrentName = CurrentNode->GetAttribute(TEXT("Name"));
		FString CurrentPath = FPaths::Combine(RelativePath, CurrentName);
		FString CurrentStringId = CurrentNode->GetAttribute(TEXT("ID"));

		FGuid CurrentId;
		FGuid::ParseExact(CurrentStringId, EGuidFormats::DigitsWithHyphensInBraces, CurrentId);
		
		if (CurrentTag == TEXT("Event"))
		{
			Visitor->EnterEvent(CurrentId, CurrentName, CurrentPath);
		}
		else if (CurrentTag == TEXT("AcousticTexture"))
		{
			if (ItemType == EWwiseItemType::Type::AcousticTexture)
			{
				Visitor->EnterAcousticTexture(CurrentId, CurrentNode, CurrentName, CurrentPath);
			}
		}
		else if (CurrentTag == TEXT("AuxBus"))
		{
			Visitor->EnterAuxBus(CurrentId, CurrentName, CurrentPath);
			recurse(CurrentNode, WorkUnitPath, CurrentPath, ItemType, CurrentId);
			Visitor->ExitAuxBus();
		}
		else if (CurrentTag == TEXT("WorkUnit"))
		{
			if (nestedWwusToParse.Contains(CurrentId))
			{
				auto info = nestedWwusToParse[CurrentId];
				info.parentGuid = ParentId;
				parseWorkUnitFile(info, CurrentPath, ItemType);
				nestedWwusToParse.Remove(CurrentId);
			}
			else
			{
				FString currentWwuPhysicalPath = FPaths::Combine(*FPaths::GetPath(WorkUnitPath), *CurrentName) + ".wwu";
				if (!unparseableWwus.Contains(currentWwuPhysicalPath))
				{
					auto info = peekWorkUnit(currentWwuPhysicalPath, ItemType);
					info.parentGuid = ParentId;
					if (info.successfullyParsed)
					{
						parseWorkUnitFile(info, CurrentPath, ItemType);
					}
					else
					{
						Visitor->RegisterError(info.wwuPath, TEXT("XML was valid, but did not have the expected structure."));
					}
				}
			}
		}
		else if (CurrentTag == TEXT("SwitchGroup"))
		{
			Visitor->EnterSwitchGroup(CurrentId, CurrentName, CurrentPath);
			recurse(CurrentNode, WorkUnitPath, CurrentPath, ItemType, CurrentId);
			Visitor->ExitSwitchGroup();
		}
		else if (CurrentTag == TEXT("Switch"))
		{
			Visitor->EnterSwitch(CurrentId, CurrentName, CurrentPath);
		}
		else if (CurrentTag == TEXT("StateGroup"))
		{
			Visitor->EnterStateGroup(CurrentId, CurrentName, CurrentPath);
			recurse(CurrentNode, WorkUnitPath, CurrentPath, ItemType, CurrentId);
			Visitor->ExitStateGroup();
		}
		else if (CurrentTag == TEXT("State"))
		{
			Visitor->EnterState(CurrentId, CurrentName, CurrentPath);
		}
		else if (CurrentTag == TEXT("GameParameter"))
		{
			Visitor->EnterGameParameter(CurrentId, CurrentName, CurrentPath);
		}
		else if (CurrentTag == TEXT("Trigger"))
		{
			Visitor->EnterTrigger(CurrentId, CurrentName, CurrentPath);
		}
		else if (CurrentTag == TEXT("Folder") || CurrentTag == TEXT("Bus"))
		{
			EWwiseItemType::Type currentItemType = EWwiseItemType::Folder;
			if (CurrentTag == TEXT("Bus"))
			{
				currentItemType = EWwiseItemType::Bus;
			}

			Visitor->EnterFolderOrBus(CurrentId, CurrentName, CurrentPath, currentItemType);
			recurse(CurrentNode, WorkUnitPath, CurrentPath, ItemType, CurrentId);
			Visitor->ExitFolderOrBus();
		}
	}

	Visitor->ExitChildrenList();
}

#undef LOCTEXT_NAMESPACE