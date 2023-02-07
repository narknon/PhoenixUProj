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

#include "AssetMigrationVisitor.h"

#include "AkAssetDatabase.h"
#include "AkAudioEvent.h"
#include "AkAuxBus.h"
#include "AkAudioBank.h"
#include "AkInitBank.h"
#include "AkSettings.h"
#include "AkAcousticTexture.h"
#include "AkUnrealHelper.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "AssetTools/Public/AssetToolsModule.h"
#include "Misc/ScopedSlowTask.h"
#include "UnrealEd/Public/ObjectTools.h"

#define LOCTEXT_NAMESPACE "AkAudio"

void AssetMigrationVisitor::OnBeginParse()
{
	auto& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

	TArray<FAssetData> allEvents;
	TArray<FAssetData> allAuxBus;
	TArray<FAssetData> allAcousticTexture;
	TArray<FAssetData> allAudioBank;
	TArray<FAssetData> allInitBank;

	auto& AssetRegistry = AssetRegistryModule.Get();
	AssetRegistry.GetAssetsByClass(UAkAudioEvent::StaticClass()->GetFName(), allEvents);
	AssetRegistry.GetAssetsByClass(UAkAuxBus::StaticClass()->GetFName(), allAuxBus);
	AssetRegistry.GetAssetsByClass(UAkAcousticTexture::StaticClass()->GetFName(), allAcousticTexture);
	AssetRegistry.GetAssetsByClass(UAkAudioBank::StaticClass()->GetFName(), allAudioBank);
	AssetRegistry.GetAssetsByClass(UAkInitBank::StaticClass()->GetFName(), allInitBank);

	FScopedSlowTask SlowTask(static_cast<float>(allEvents.Num() + allAuxBus.Num() + allAcousticTexture.Num()), LOCTEXT("AK_ScanAssets", "Scanning sound data assets..."));
	SlowTask.MakeDialog();

	auto processAssetData = [&SlowTask](const FAssetData& assetData, TMap<FString, TArray<UObject*>>& duplicateMap) {
		FString assetName = assetData.AssetName.ToString();
		FString Message = FString::Printf(TEXT("Scanning sound data asset: %s"), *assetName);
		SlowTask.EnterProgressFrame(1.0f, FText::FromString(Message));

		auto* assetInstance = assetData.GetAsset();
		duplicateMap.FindOrAdd(assetName).Add(assetInstance);
	};

	for (auto& assetData : allEvents)
	{
		processAssetData(assetData, duplicatedEvents);
	}

	for (auto& assetData : allAuxBus)
	{
		processAssetData(assetData, duplicatedAuxBus);
	}

	for (auto& assetData : allAcousticTexture)
	{
		processAssetData(assetData, duplicatedAcousticTextures);
	}

	auto& akAssetDatabase = AkAssetDatabase::Get();

	akAssetDatabase.AcousticTextureMap.Empty();
	akAssetDatabase.AuxBusMap.Empty();
	akAssetDatabase.BankMap.Empty();
	akAssetDatabase.EventMap.Empty();
	akAssetDatabase.AudioTypeMap.TypeMap.Empty();

	for (auto& assetData : allAudioBank)
	{
		auto audioBank = Cast<UAkAudioBank>(assetData.GetAsset());
		if (audioBank)
		{
			if (!audioBank->ID.IsValid())
			{
				audioBank->ID = FGuid::NewGuid();
				audioBank->MarkPackageDirty();

				packagesToSave.AddUnique(audioBank->GetOutermost());
			}

			akAssetDatabase.Add(audioBank->ID, audioBank);
		}
	}

	if (allInitBank.Num() > 0)
	{
		ObjectTools::DeleteAssets(allInitBank);
	}

	akAssetDatabase.CreateInitBankIfNeeded();
}

void AssetMigrationVisitor::EnterEvent(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	migrateAssets<UAkAudioEvent>(Id, Name, duplicatedEvents);

	Super::EnterEvent(Id, Name, RelativePath);
}

void AssetMigrationVisitor::EnterAuxBus(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	migrateAssets<UAkAuxBus>(Id, Name, duplicatedAuxBus);

	Super::EnterAuxBus(Id, Name, RelativePath);
}

void AssetMigrationVisitor::EnterAcousticTexture(const FGuid& Id, const class FXmlNode* CurrentNode, const FString& Name, const FString& RelativePath)
{
	migrateAssets<UAkAcousticTexture>(Id, Name, duplicatedAcousticTextures);

	Super::EnterAcousticTexture(Id, CurrentNode, Name, RelativePath);
}

void AssetMigrationVisitor::End()
{
	Super::End();

	auto* AkSettings = GetDefault<UAkSettings>();
	if (AkSettings && AkSettings->FixupRedirectorsDuringMigration)
	{
		AkAssetDatabase::Get().FixUpRedirectors(AkUnrealHelper::GetBaseAssetPackagePath());
	}
}

#if UE_4_23_OR_LATER
// Copy of ObjectTools::ConsolidateObjects with only what we need. This is for use in a commandlet only, to workaround a crash
// when calling ObjectTools::ConsolidateObjects from a Commandlet. Note that ConsolidateObjects only crashes in 4.23 and up.
bool AssetMigrationVisitor::AkConsolidateObjects(UObject* ObjectToConsolidateTo, TArray<UObject*>& ObjectsToConsolidate)
{
	// Ensure the consolidation is headed toward a valid object and this isn't occurring in game
	if (ObjectToConsolidateTo)
	{
		// Keep track of objects which became partially consolidated but couldn't be deleted for some reason;
		// these are critical failures, and the user needs to be alerted
		TArray<UObject*> CriticalFailureObjects;

		// List of objects successfully deleted
		TArray<UObject*> ConsolidatedObjects;

		// A list of names for object redirectors created during the delete process
		// This is needed because the redirectors may not have the same name as the
		// objects they are replacing until the objects are garbage collected
		TMap<UObjectRedirector*, FName> RedirectorToObjectNameMap;

		// Scope the reregister context below to complete after object deletion and before garbage collection
		ObjectTools::ForceReplaceReferences(ObjectToConsolidateTo, ObjectsToConsolidate);

		TSet<FString> AlreadyMappedObjectPaths;

		// With all references to the objects to consolidate to eliminated from objects that are currently loaded, it should now be safe to delete
		// the objects to be consolidated themselves, leaving behind a redirector in their place to fix up objects that were not currently loaded at the time
		// of this operation.
		for (TArray<UObject*>::TConstIterator ConsolIter(ObjectsToConsolidate); ConsolIter; ++ConsolIter)
		{
			UObject* CurObjToConsolidate = *ConsolIter;
			UObject* CurObjOuter = CurObjToConsolidate->GetOuter();
			UPackage* CurObjPackage = CurObjToConsolidate->GetOutermost();
			const FName CurObjName = CurObjToConsolidate->GetFName();
			const FString CurObjPath = CurObjToConsolidate->GetPathName();

			// Attempt to delete the object that was consolidated
			if (ObjectTools::DeleteSingleObject(CurObjToConsolidate))
			{
				// DONT GC YET!!! we still need these objects around to notify other tools that they are gone and to create redirectors
				ConsolidatedObjects.Add(CurObjToConsolidate);

				if (AlreadyMappedObjectPaths.Contains(CurObjPath))
				{
					continue;
				}

				// Create a redirector with a unique name
				// It will have the same name as the object that was consolidated after the garbage collect
				UObjectRedirector* Redirector = NewObject<UObjectRedirector>(CurObjOuter, NAME_None, RF_Standalone | RF_Public);
				check(Redirector);

				// Set the redirector to redirect to the object to consolidate to
				Redirector->DestinationObject = ObjectToConsolidateTo;

				// Keep track of the object name so we can rename the redirector later
				RedirectorToObjectNameMap.Add(Redirector, CurObjName);
				AlreadyMappedObjectPaths.Add(CurObjPath);
			}
			// If the object couldn't be deleted, store it in the array that will be used to show the user which objects had errors
			else
			{
				CriticalFailureObjects.Add(CurObjToConsolidate);
			}
		}

		// Now that the old objects have been garbage collected, give the redirectors a proper name
		for (TMap<UObjectRedirector*, FName>::TIterator RedirectIt(RedirectorToObjectNameMap); RedirectIt; ++RedirectIt)
		{
			UObjectRedirector* Redirector = RedirectIt.Key();
			const FName ObjName = RedirectIt.Value();

			if (Redirector->Rename(*ObjName.ToString(), NULL, REN_Test))
			{
				Redirector->Rename(*ObjName.ToString(), NULL, REN_DontCreateRedirectors | REN_ForceNoResetLoaders | REN_NonTransactional);
				FAssetRegistryModule::AssetCreated(Redirector);
			}
			else
			{
				// Could not rename the redirector back to the original object's name. This indicates the original
				// object could not be garbage collected even though DeleteSingleObject returned true.
				CriticalFailureObjects.AddUnique(Redirector);
			}
		}

		// Empty the provided array so it's not full of pointers to deleted objects
		ObjectsToConsolidate.Empty();
		ConsolidatedObjects.Empty();

		if (CriticalFailureObjects.Num() == 0)
		{
			// Success!
			return true;
		}
	}

	return false;
}
#endif

template<typename AssetType>
void AssetMigrationVisitor::migrateAssets(const FGuid& Id, const FString& Name, TMap<FString, TArray<UObject*>>& duplicatedAssets)
{
	auto& assetDatabase = AkAssetDatabase::Get();

	TArray<UObject*>* duplicatedIt = duplicatedAssets.Find(Name);
	if (duplicatedIt && duplicatedIt->Num() > 0)
	{
		auto wwiseAssetPath = AkUnrealHelper::GetBaseAssetPackagePath();

		UObject* original = nullptr;

		for (int32 i = 0; i < duplicatedIt->Num(); ++i)
		{
			auto currentObject = duplicatedIt->operator[](i);

			if (currentObject->GetPathName().StartsWith(wwiseAssetPath))
			{
				original = currentObject;
				duplicatedIt->RemoveAt(i);
				break;
			}
		}

		if (!original)
		{
			original = duplicatedIt->operator[](0);
			duplicatedIt->RemoveAt(0);
		}

		if (auto akAsset = Cast<AssetType>(original))
		{
			akAsset->ID = Id;
			akAsset->MarkPackageDirty();
			
			assetDatabase.Add(Id, akAsset);
		}

		if (duplicatedIt->Num() > 0)
		{
#if UE_4_23_OR_LATER
			if (IsRunningCommandlet())
			{
				AkConsolidateObjects(original, *duplicatedIt);
			}
			else
#endif
			{
				ObjectTools::ConsolidateObjects(original, *duplicatedIt);
			}
		}

		duplicatedIt->Empty();
	}
}

void AssetMigrationVisitor::collectExtraAssetsToDelete(TArray<FAssetData>& assetToDelete)
{
	for (auto& eventEntry : duplicatedEvents)
	{
		for (auto value : eventEntry.Value)
		{
			assetToDelete.Emplace(value);
		}
	}

	for (auto& auxBusEntry : duplicatedAuxBus)
	{
		for (auto value : auxBusEntry.Value)
		{
			assetToDelete.Emplace(value);
		}
	}

	for (auto& acousticTextureEntry : duplicatedAcousticTextures)
	{
		for (auto value : acousticTextureEntry.Value)
		{
			assetToDelete.Emplace(value);
		}
	}
}

#undef LOCTEXT_NAMESPACE
