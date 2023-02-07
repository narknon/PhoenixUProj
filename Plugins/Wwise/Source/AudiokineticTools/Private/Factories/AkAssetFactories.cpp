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


#include "AkAssetFactories.h"

#include "AkAcousticTexture.h"
#include "AkAudioBank.h"
#include "AkAudioEvent.h"
#include "AkAuxBus.h"
#include "AkGroupValue.h"
#include "AkMediaAsset.h"
#include "AkRtpc.h"
#include "AkSettings.h"
#include "AkSettingsPerUser.h"
#include "AkStateValue.h"
#include "AkSwitchValue.h"
#include "AkTrigger.h"
#include "AkUnrealHelper.h"
#include "AkWaapiUtils.h"
#include "AssetManagement/AkAssetDatabase.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "AssetTools/Public/AssetToolsModule.h"
#include "Core/Public/Hash/CityHash.h"
#include "HAL/FileManager.h"
#if UE_5_0_OR_LATER
#include "HAL/PlatformFileManager.h"
#else
#include "HAL/PlatformFilemanager.h"
#endif
#include "Misc/MessageDialog.h"
#include "Misc/Paths.h"
#include "ToolBehavior/AkToolBehavior.h"

DEFINE_LOG_CATEGORY_STATIC(LogAkAssetFactory, Log, All);

struct AkAssetFactory_Helper
{
	enum class WwiseSync
	{
		Enabled,
		Disabled
	};

	template<typename AkAssetType, WwiseSync DoWwiseSync = WwiseSync::Enabled>
	static UObject* FactoryCreateNew(UClass* Class, UObject* InParent, const FName& Name, EObjectFlags Flags, FGuid AssetID = FGuid{})
	{
		auto AkSettingsPerUser = GetDefault<UAkSettingsPerUser>();

		bool WAAPIAvailable = FAkWaapiClient::IsProjectLoaded();
		bool isUsingEventBased = AkUnrealHelper::IsUsingEventBased();
		bool UsingAutoSync = isUsingEventBased ? AkSettingsPerUser->EnableAutomaticAssetSynchronization : false;
		const auto BasePath = AkUnrealHelper::GetBaseAssetPackagePath();
		auto BaseWwiseTypePath = BasePath / AkAssetTraits<AkAssetType>::BaseFolder();
		auto ContainingPath = InParent->GetName();

		if (UsingAutoSync && !WAAPIAvailable)
		{
			// We're using auto-sync, but WAAPI is not available. In that mode, Wwise should push objects to Unreal, and that's it. 
			// Disallow asset creation, except for SoundBanks (which have no Wwise project counterpart)
			if (AkAssetType::StaticClass() != UAkAudioBank::StaticClass())
			{
				FMessageDialog::Open(EAppMsgType::Ok, NSLOCTEXT("AkAssetFactory", "CannotCreateAssetAutoSyncNoWaapi", "Attempting to create a new asset with Automatic synchronization enabled, but WAAPI is unavailable. Please create your asset in the Wwise Authoring Application."));
				return nullptr;
			}
		}

		// Whether we're using WAAPI or not, or using auto-sync or not, an asset name starting with a digit is illegal in Wwise.
		auto assetName = Name.ToString();
		if (!assetName.IsEmpty() && FChar::IsDigit(assetName[0]))
		{
			const FFormatNamedArguments Args
			{
				{ TEXT("ObjectName"), FText::FromName(Name) },
				{ TEXT("ClassName"), FText::FromString(Class->GetName()) },
				{ TEXT("PathName"), FText::FromString(ContainingPath) },
			};

			FMessageDialog::Open(EAppMsgType::Ok, FText::Format(NSLOCTEXT("AkAssetFactory", "CannotCreateAssetInPath", "Cannot create new asset '{ObjectName}' of class '{ClassName}' in path '{PathName}' because it starts with a numeric character, which is illegal in Wwise."), Args));
			return nullptr;
		}

		if (!AkToolBehavior::Get()->AkAssetFactory_ValidNewAssetPath(Name, ContainingPath, Class))
		{
			return nullptr;
		}

		FGuid NewObjectID = AssetID;
		bool ObjectNeedsDirtying = false;

		if (AssetID.IsValid())
		{
			ObjectNeedsDirtying = true;
		}

		// If we're pushing the asset to Wwise, it needs to be in the appropriate folder
		if (DoWwiseSync == WwiseSync::Enabled && UsingAutoSync && WAAPIAvailable)
		{
			auto waapiClient = FAkWaapiClient::Get();
			if (waapiClient)
			{
				auto ParentPath = ConvertAssetPathToWwisePath(ContainingPath, assetName, BasePath);
				TSharedRef<FJsonObject> args = MakeShareable(new FJsonObject());
				args->SetStringField(WwiseWaapiHelper::NAME, assetName);
				args->SetStringField(WwiseWaapiHelper::PARENT, ParentPath);
				args->SetStringField(WwiseWaapiHelper::NOTES, "Created in Unreal Engine via WAAPI");
				args->SetStringField(WwiseWaapiHelper::TYPE, AkAssetTraits<AkAssetType>::Name());

				TSharedRef<FJsonObject> options = MakeShareable(new FJsonObject());
				TSharedPtr<FJsonObject> result;

				if (!waapiClient->Call(ak::wwise::core::object::create, args, options, result))
				{
					const FFormatNamedArguments Args
					{
						{ TEXT("ObjectName"), FText::FromName(Name) },
						{ TEXT("ClassName"), FText::FromString(Class->GetName()) },
						{ TEXT("WwisePathName"), FText::FromString(ContainingPath) },
					};

					FMessageDialog::Open(EAppMsgType::Ok, FText::Format(NSLOCTEXT("AkAssetFactory", "CannotCreateAssetWaapiError", "Cannot create new asset '{ObjectName}' of class '{ClassName}' in Wwise project path '{WwisePathName}' due to WAAPI error."), Args));
					return nullptr;
				}

				FString Id;
				if (result->TryGetStringField(WwiseWaapiHelper::ID, Id) && FGuid::ParseExact(Id, EGuidFormats::DigitsWithHyphensInBraces, NewObjectID))
				{
					ObjectNeedsDirtying = true;
				}
			}
			else
			{
				const FFormatNamedArguments Args
				{
					{ TEXT("ObjectName"), FText::FromName(Name) },
					{ TEXT("ClassName"), FText::FromString(Class->GetName()) },
					{ TEXT("WwisePathName"), FText::FromString(ContainingPath) },
				};

				FMessageDialog::Open(EAppMsgType::Ok, FText::Format(NSLOCTEXT("AkAssetFactory", "CannotCreateAssetWaapiError", "Cannot create new asset '{ObjectName}' of class '{ClassName}' in Wwise project path '{WwisePathName}' due to WAAPI error."), Args));
				return nullptr;
			}
		}

		auto newObject = NewObject<AkAssetType>(InParent, Name, Flags);
		if (ObjectNeedsDirtying)
		{
			newObject->ID = NewObjectID;
			newObject->MarkPackageDirty();
		}
		return newObject;
	}

	template<typename AkAssetType>
	static bool CanCreateNew()
	{
		const UAkSettings* akSettings = GetDefault<UAkSettings>();
		if (akSettings)
		{
			if (!akSettings->UseEventBasedPackaging)
			{
				return AkAssetType::StaticClass() == UAkAcousticTexture::StaticClass()
					|| AkAssetType::StaticClass() == UAkAudioBank::StaticClass()
					|| AkAssetType::StaticClass() == UAkAuxBus::StaticClass()
					|| AkAssetType::StaticClass() == UAkAudioEvent::StaticClass();
			}

			return true;
		}
		return false;
	}

private:
	static FString ConvertAssetPathToWwisePath(FString ContainingPath, const FString& AssetName, const FString& BasePath)
	{
		ContainingPath.RemoveFromStart(BasePath, ESearchCase::IgnoreCase);
		ContainingPath.RemoveFromEnd(FString("/") + AssetName);
		return ContainingPath.Replace(TEXT("/"), TEXT("\\")).Replace(TEXT("_"), TEXT(" "));
	}
};

//////////////////////////////////////////////////////////////////////////
// UAkAcousticTextureFactory

UAkAcousticTextureFactory::UAkAcousticTextureFactory(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UAkAcousticTexture::StaticClass();
	bCreateNew = bEditorImport = bEditAfterNew = true;
}

UObject* UAkAcousticTextureFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return AkAssetFactory_Helper::FactoryCreateNew<UAkAcousticTexture>(Class, InParent, Name, Flags, AssetID);
}

bool UAkAcousticTextureFactory::CanCreateNew() const
{
	return AkAssetFactory_Helper::CanCreateNew<UAkAcousticTexture>();
}

//////////////////////////////////////////////////////////////////////////
// UAkAudioBankFactory

UAkAudioBankFactory::UAkAudioBankFactory(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UAkAudioBank::StaticClass();
	bCreateNew = bEditorImport = bEditAfterNew = true;

	// Turn off auto-re-import for this factory.
	ImportPriority = -1;
}

UObject* UAkAudioBankFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	if (!AkToolBehavior::Get()->AkAssetFactory_ValidNewAssetPath(Name, InParent->GetName(), Class))
	{
		return nullptr;
	}

	auto assetName = Name.ToString();

	if (!assetName.IsEmpty() && FChar::IsDigit(assetName[0]))
	{
		const FFormatNamedArguments Args
		{
			{ TEXT("ObjectName"), FText::FromName(Name) },
			{ TEXT("ClassName"), FText::FromString(Class->GetName()) },
		};

		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(NSLOCTEXT("AkAssetFactory", "CannotCreateAssetInPath", "Cannot create new asset '{ObjectName}' of class '{ClassName}' because it starts with a numeric character."), Args));
		return nullptr;
	}

	auto audioBank = NewObject<UAkAudioBank>(InParent, Name, Flags);
	audioBank->ID = FGuid::NewGuid();
	return audioBank;
}

bool UAkAudioBankFactory::CanCreateNew() const
{
	return AkAssetFactory_Helper::CanCreateNew<UAkAudioBank>();
}

//////////////////////////////////////////////////////////////////////////
// UAkAudioEventFactory

UAkAudioEventFactory::UAkAudioEventFactory(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UAkAudioEvent::StaticClass();
	bCreateNew = bEditorImport = bEditAfterNew = true;
}

UObject* UAkAudioEventFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return AkAssetFactory_Helper::FactoryCreateNew<UAkAudioEvent>(Class, InParent, Name, Flags, AssetID);
}

bool UAkAudioEventFactory::CanCreateNew() const
{
	return AkAssetFactory_Helper::CanCreateNew<UAkAudioEvent>();
}

//////////////////////////////////////////////////////////////////////////
// UAkAuxBusFactory

UAkAuxBusFactory::UAkAuxBusFactory(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UAkAuxBus::StaticClass();
	bCreateNew = bEditorImport = bEditAfterNew = true;
}

UObject* UAkAuxBusFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return AkAssetFactory_Helper::FactoryCreateNew<UAkAuxBus>(Class, InParent, Name, Flags, AssetID);
}

bool UAkAuxBusFactory::CanCreateNew() const
{
	return AkAssetFactory_Helper::CanCreateNew<UAkAuxBus>();
}

//////////////////////////////////////////////////////////////////////////
// UAkRtpcFactory

UAkRtpcFactory::UAkRtpcFactory(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UAkRtpc::StaticClass();
	bCreateNew = bEditorImport = bEditAfterNew = true;
}

UObject* UAkRtpcFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return AkAssetFactory_Helper::FactoryCreateNew<UAkRtpc>(Class, InParent, Name, Flags, AssetID);
}

bool UAkRtpcFactory::CanCreateNew() const
{
	return AkAssetFactory_Helper::CanCreateNew<UAkRtpc>();
}

//////////////////////////////////////////////////////////////////////////
// UAkTriggerFactory

UAkTriggerFactory::UAkTriggerFactory(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UAkTrigger::StaticClass();
	bCreateNew = bEditorImport = bEditAfterNew = true;
}

UObject* UAkTriggerFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return AkAssetFactory_Helper::FactoryCreateNew<UAkTrigger>(Class, InParent, Name, Flags, AssetID);
}

bool UAkTriggerFactory::CanCreateNew() const
{
	return AkAssetFactory_Helper::CanCreateNew<UAkTrigger>();
}

//////////////////////////////////////////////////////////////////////////
// UAkExternalSourceFactory

UAkExternalSourceFactory::UAkExternalSourceFactory(const class FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	SupportedClass = UAkExternalMediaAsset::StaticClass();
	Formats.Add(TEXT("wem;Audiokinetic Audio File"));
	bEditorImport = 1;
	ImportPriority = 101;
}

UObject* UAkExternalSourceFactory::FactoryCreateFile(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	if (!AkUnrealHelper::IsUsingEventBased())
	{
		return nullptr;
	}

	auto relativePath = Filename;
	FPaths::MakePathRelativeTo(relativePath, *(AkUnrealHelper::GetExternalSourceDirectory() + TEXT("/")));
	FString platform = relativePath.Left(relativePath.Find(TEXT("/")));

	FString assetName = Name.ToString();

	FString assetPath = FPaths::Combine(AkUnrealHelper::GetExternalSourceAssetPackagePath(), FString::Printf(TEXT("%s.%s"), *assetName, *assetName));

	auto& AssetRegistryModule = FModuleManager::GetModuleChecked<FAssetRegistryModule>("AssetRegistry");
	auto& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");

	UAkExternalMediaAsset* mediaInstance = nullptr;
	bool bMarkAsDirty =false;

	auto assetData = AssetRegistryModule.Get().GetAssetByObjectPath(*assetPath);
	if (assetData.IsValid())
	{
		mediaInstance = Cast<UAkExternalMediaAsset>(assetData.GetAsset());
	}
	else
	{
		mediaInstance = Cast<UAkExternalMediaAsset>(AssetToolsModule.Get().CreateAsset(assetName, FPaths::GetPath(assetPath), UAkExternalMediaAsset::StaticClass(), nullptr));
	}

	if (!mediaInstance)
	{
		UE_LOG(LogAkAssetFactory, Error, TEXT("Failed to import external source %s"), *Filename);
		return nullptr;
	}

	if (mediaInstance->MediaName != assetName)
	{
		mediaInstance->MediaName = assetName;
		bMarkAsDirty =true;
	}

	auto& platformFile = FPlatformFileManager::Get().GetPlatformFile();

	auto mediaPlatformData = mediaInstance->FindOrAddMediaAssetData(platform);
	if (mediaPlatformData->AssetPlatform != platform)
	{
		mediaPlatformData->AssetPlatform = platform;
		bMarkAsDirty = true;
	}

	auto fileSize = platformFile.FileSize(*Filename);
	TUniquePtr<IFileHandle> fileReader(platformFile.OpenRead(*Filename));
	if (fileReader)
	{
		TArray<uint8> tempData;
		tempData.Reserve(fileSize);

		fileReader->Read(tempData.GetData(), fileSize);

		auto newHash = CityHash64(reinterpret_cast<const char*>(tempData.GetData()), fileSize);

		if (mediaPlatformData->MediaContentHash != newHash)
		{
			{
				FScopeLock autoLock(&mediaPlatformData->DataLock);
				for (auto& chunk : mediaPlatformData->DataChunks)
				{
					if (chunk.Data.IsLocked())
					{
						chunk.Data.Unlock();
					}
				}
				mediaPlatformData->DataChunks.Empty();
			}

			fileReader->Seek(0);

			FAkMediaDataChunk* dataChunk = new FAkMediaDataChunk;
			dataChunk->IsPrefetch = false;

			dataChunk->Data.SetBulkDataFlags(BULKDATA_Force_NOT_InlinePayload);

			dataChunk->Data.Lock(EBulkDataLockFlags::LOCK_READ_WRITE);

			void* rawData = dataChunk->Data.Realloc(fileSize);
			fileReader->Read(reinterpret_cast<uint8*>(rawData), fileSize);

			dataChunk->Data.Unlock();

			{
				FScopeLock autoLock(&mediaPlatformData->DataLock);
				mediaPlatformData->DataChunks.Add(dataChunk);
			}

			mediaPlatformData->MediaContentHash = newHash;
			bMarkAsDirty = true;
		}
	}
	if (bMarkAsDirty)
	{
		mediaInstance->MarkPackageDirty();
	}

	// Since we are reusing another asset, do not return an asset instance. We did not create anything.
	UE_LOG(LogAkAssetFactory, Log, TEXT("Successfully imported external source %s. Please ignore the Unreal log message saying the import failed."), *Filename);
	return nullptr;
}

bool UAkExternalSourceFactory::FactoryCanImport(const FString& Filename)
{
	if (!AkUnrealHelper::IsUsingEventBased())
	{
		return false;
	}

	if (FPaths::GetExtension(Filename) == TEXT("wem"))
	{
		if (Filename.Contains(FPaths::Combine(AkUnrealHelper::GetExternalSourceDirectory())))
		{
			return true;
		}
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////
// UAkStateValueFactory

UAkStateValueFactory::UAkStateValueFactory(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UAkStateValue::StaticClass();
	bCreateNew = bEditorImport = bEditAfterNew = true;
}

UObject* UAkStateValueFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return AkAssetFactory_Helper::FactoryCreateNew<UAkStateValue, AkAssetFactory_Helper::WwiseSync::Disabled>(Class, InParent, Name, Flags, AssetID);
}

//////////////////////////////////////////////////////////////////////////
// UAkSwitchValueFactory

UAkSwitchValueFactory::UAkSwitchValueFactory(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UAkSwitchValue::StaticClass();
	bCreateNew = bEditorImport = bEditAfterNew = true;
}

UObject* UAkSwitchValueFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return AkAssetFactory_Helper::FactoryCreateNew<UAkSwitchValue, AkAssetFactory_Helper::WwiseSync::Disabled>(Class, InParent, Name, Flags, AssetID);
}
