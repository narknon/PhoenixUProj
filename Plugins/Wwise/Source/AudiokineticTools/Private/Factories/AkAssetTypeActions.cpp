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


#include "AkAssetTypeActions.h"

#include "AkAudioBank.h"
#include "AkAudioBankGenerationHelpers.h"
#include "AkAudioDevice.h"
#include "AkAudioEvent.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "IAssetTools.h"
#include "ObjectEditorUtils.h"
#include "ObjectTools.h"
#include "Interfaces/IMainFrameModule.h"
#include "Misc/ScopeLock.h"
#include "Toolkits/SimpleAssetEditor.h"
#include "UI/SAkAudioBankPicker.h"
#include "UObject/Package.h"

#define LOCTEXT_NAMESPACE "AkAssetTypeActions"

namespace FAkAssetTypeActions_Helpers
{
	FCriticalSection CriticalSection;
	TMap<FString, AkPlayingID> PlayingAkEvents;

	void AkEventPreviewCallback(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo)
	{
		auto EventInfo = static_cast<AkEventCallbackInfo*>(in_pCallbackInfo);
		if (!EventInfo)
			return;

		FScopeLock Lock(&CriticalSection);
		for (auto& PlayingEvent : PlayingAkEvents)
		{
			if (PlayingEvent.Value == EventInfo->playingID)
			{
				PlayingAkEvents.Remove(PlayingEvent.Key);
				return;
			}
		}
	}

	template<bool PlayOne>
	void PlayEvents(const TArray<TWeakObjectPtr<UAkAudioEvent>>& InObjects)
	{
		auto AudioDevice = FAkAudioDevice::Get();
		if (!AudioDevice)
			return;

		for (auto& Obj : InObjects)
		{
			auto Event = Obj.Get();
			if (!Event)
				continue;

			AkPlayingID* foundID;
			{
				FScopeLock Lock(&CriticalSection);
				foundID = PlayingAkEvents.Find(Event->GetName());
			}

			if (foundID)
			{
				AudioDevice->StopPlayingID(*foundID);
			}
			else
			{
				auto CurrentPlayingID = AudioDevice->PostEvent(Event, nullptr, AK_EndOfEvent, &AkEventPreviewCallback);
				if (CurrentPlayingID != AK_INVALID_PLAYING_ID)
				{
					FScopeLock Lock(&CriticalSection);
					PlayingAkEvents.FindOrAdd(Event->GetName()) = CurrentPlayingID;
				}
			}

			if (PlayOne)
				break;
		}
	}

	void ClearAssetData(const TArray<TWeakObjectPtr<UAkAssetBase>>& InObjects, bool DeleteAssets)
	{
		TArray<FAssetData> AssetsToDelete;
		for (const TWeakObjectPtr<UAkAssetBase>& Asset : InObjects)
		{
			if (Asset.IsValid())
			{
				auto AssetInstance = Asset.Get();
				AssetInstance->UnloadBank();
				AssetInstance->Reset(AssetsToDelete);
			}
		}
		if (DeleteAssets)
		{
			ObjectTools::DeleteAssets(AssetsToDelete, true);
		}
	}

}

//////////////////////////////////////////////////////////////////////////
// FAssetTypeActions_AkAcousticTexture

void FAssetTypeActions_AkAcousticTexture::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	FSimpleAssetEditor::CreateEditor(EToolkitMode::Standalone, EditWithinLevelEditor, InObjects);
}


//////////////////////////////////////////////////////////////////////////
// FAssetTypeActions_AkAudioBank

void FAssetTypeActions_AkAudioBank::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	auto Banks = GetTypedWeakObjectPtrs<UAkAudioBank>(InObjects);

	if (Banks.Num() > 1)
	{
		MenuBuilder.AddMenuEntry(
			LOCTEXT("AkAudioBank_GenerateSelectedSoundBanks", "Generate Selected SoundBanks..."),
			LOCTEXT("AkAudioBank_GenerateSelectedSoundBanksTooltip", "Generates the selected SoundBanks."),
			FSlateIcon(),
			FUIAction(
				FExecuteAction::CreateSP(this, &FAssetTypeActions_AkAudioBank::CreateGenerateSoundDataWindow, Banks),
				FCanExecuteAction()
			)
		);
	}
	else
	{
		MenuBuilder.AddMenuEntry(
			LOCTEXT("AkAudioBank_GenerateSelectedSoundBank", "Generate Selected SoundBank..."),
			LOCTEXT("AkAudioBank_GenerateSelectedSoundBankTooltip", "Generates the selected SoundBank."),
			FSlateIcon(),
			FUIAction(
				FExecuteAction::CreateSP(this, &FAssetTypeActions_AkAudioBank::CreateGenerateSoundDataWindow, Banks),
				FCanExecuteAction()
			)
		);
	}

	MenuBuilder.AddMenuEntry(
		LOCTEXT("AkAudioBank_RefreshAllBanks", "Refresh All Banks"),
		LOCTEXT("AkAudioBank_RefreshAllBanksTooltip", "Refresh all the selected banks."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateSP(this, &FAssetTypeActions_AkAudioBank::RefreshAllBanks, Banks),
			FCanExecuteAction()
		)
	);

	FAkAssetTypeActions_ClearableBase<UAkAudioBank>::GetActions(InObjects, MenuBuilder);
}

void FAssetTypeActions_AkAudioBank::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	FSimpleAssetEditor::CreateEditor(EToolkitMode::Standalone, EditWithinLevelEditor, InObjects);
}

#if UE_4_24_OR_LATER
bool FAssetTypeActions_AkAudioBank::AssetsActivatedOverride(const TArray<UObject*>& InObjects, EAssetTypeActivationMethod::Type ActivationType)
#else
void FAssetTypeActions_AkAudioBank::AssetsActivated(const TArray<UObject*>& InObjects, EAssetTypeActivationMethod::Type ActivationType)
#endif
{
	if (ActivationType == EAssetTypeActivationMethod::DoubleClicked || ActivationType == EAssetTypeActivationMethod::Opened)
	{
		if (InObjects.Num() == 1)
		{
#if UE_4_24_OR_LATER
			return GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(InObjects[0]);
#else
			FAssetEditorManager::Get().OpenEditorForAsset(InObjects[0]);
#endif
		}
		else if (InObjects.Num() > 1)
		{
#if UE_4_24_OR_LATER
			return GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAssets(InObjects);
#else
			FAssetEditorManager::Get().OpenEditorForAssets(InObjects);
#endif
		}
	}

#if UE_4_24_OR_LATER
	return true;
#endif
}

void FAssetTypeActions_AkAudioBank::CreateGenerateSoundDataWindow(TArray<TWeakObjectPtr<UAkAudioBank>> Objects)
{
	AkAudioBankGenerationHelper::CreateGenerateSoundDataWindow(&Objects);
}

void FAssetTypeActions_AkAudioBank::RefreshAllBanks(TArray<TWeakObjectPtr<UAkAudioBank>> Objects)
{
	FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AudioDevice->ReloadAllSoundData();
	}
}

//////////////////////////////////////////////////////////////////////////
// FAssetTypeActions_AkInitBank

void FAssetTypeActions_AkInitBank::GetActions(const TArray<UObject*>& InObjects,
	FMenuBuilder& MenuBuilder)
{
	FAkAssetTypeActions_ClearableBase<UAkInitBank>::GetActions(InObjects, MenuBuilder);
}

//////////////////////////////////////////////////////////////////////////
// FAssetTypeActions_AkGroupValue

void FAssetTypeActions_AkGroupValue::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	FAkAssetTypeActions_ClearableBase<UAkGroupValue>::GetActions(InObjects, MenuBuilder);
}

//////////////////////////////////////////////////////////////////////////
// FAssetTypeActions_AkAudioEvent

void FAssetTypeActions_AkAudioEvent::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	auto Events = GetTypedWeakObjectPtrs<UAkAudioEvent>(InObjects);

	MenuBuilder.AddMenuEntry(
		LOCTEXT("AkAudioEvent_PlayEvent", "Play Event"),
		LOCTEXT("AkAudioEvent_PlayEventTooltip", "Plays the selected event."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateSP(this, &FAssetTypeActions_AkAudioEvent::PlayEvent, Events),
			FCanExecuteAction()
		)
	);

	MenuBuilder.AddMenuEntry(
		LOCTEXT("AkAudioEvent_StopEvent", "Stop Event"),
		LOCTEXT("AkAudioEvent_StopEventTooltip", "Stops the selected event."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateSP(this, &FAssetTypeActions_AkAudioEvent::StopEvent, Events),
			FCanExecuteAction()
		)
	);

	MenuBuilder.AddMenuEntry(
		LOCTEXT("AkAudioEvent_GroupIntoSoundBank", "Group Into Sound Bank"),
		LOCTEXT("AkAudioEvent_GroupIntoSoundBankTooltip", "Group the selected events into a sound bank."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateSP(this, &FAssetTypeActions_AkAudioEvent::GroupIntoSoundBank, Events),
			FCanExecuteAction()
		)
	);
	FAkAssetTypeActions_ClearableBase<UAkAudioEvent>::GetActions(InObjects, MenuBuilder);
}

void FAssetTypeActions_AkAudioEvent::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	FSimpleAssetEditor::CreateEditor(EToolkitMode::Standalone, EditWithinLevelEditor, InObjects);
}

#if UE_4_24_OR_LATER
bool FAssetTypeActions_AkAudioEvent::AssetsActivatedOverride(const TArray<UObject*>& InObjects, EAssetTypeActivationMethod::Type ActivationType)
#else
void FAssetTypeActions_AkAudioEvent::AssetsActivated(const TArray<UObject*>& InObjects, EAssetTypeActivationMethod::Type ActivationType)
#endif
{
	if (ActivationType == EAssetTypeActivationMethod::DoubleClicked || ActivationType == EAssetTypeActivationMethod::Opened)
	{
		if (InObjects.Num() == 1)
		{
#if UE_4_24_OR_LATER
			return GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(InObjects[0]);
#else
			FAssetEditorManager::Get().OpenEditorForAsset(InObjects[0]);
#endif
		}
		else if (InObjects.Num() > 1)
		{
#if UE_4_24_OR_LATER
			return GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAssets(InObjects);
#else
			FAssetEditorManager::Get().OpenEditorForAssets(InObjects);
#endif
		}
	}
	else if (ActivationType == EAssetTypeActivationMethod::Previewed)
	{
		auto Events = GetTypedWeakObjectPtrs<UAkAudioEvent>(InObjects);
		FAkAssetTypeActions_Helpers::PlayEvents<true>(Events);
	}

#if UE_4_24_OR_LATER
	return true;
#endif
}

void FAssetTypeActions_AkAudioEvent::PlayEvent(TArray<TWeakObjectPtr<UAkAudioEvent>> Objects)
{
	FAkAssetTypeActions_Helpers::PlayEvents<false>(Objects);
}

void FAssetTypeActions_AkAudioEvent::StopEvent(TArray<TWeakObjectPtr<UAkAudioEvent>> Objects)
{
	FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AudioDevice->StopGameObject(nullptr);
	}
}

void FAssetTypeActions_AkAudioEvent::GroupIntoSoundBank(TArray<TWeakObjectPtr<UAkAudioEvent>> Objects)
{
	TSharedPtr<SAkAudioBankPicker> WindowContent;

	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(LOCTEXT("WindowTitle", "Select Sound Bank"))
		.SizingRule(ESizingRule::Autosized)
		;

	Window->SetContent
	(
		SAssignNew(WindowContent, SAkAudioBankPicker)
		.WidgetWindow(Window)
	);

	TSharedPtr<SWindow> ParentWindow;

	if (FModuleManager::Get().IsModuleLoaded("MainFrame"))
	{
		IMainFrameModule& MainFrame = FModuleManager::LoadModuleChecked<IMainFrameModule>("MainFrame");
		ParentWindow = MainFrame.GetParentWindow();
	}

	FSlateApplication::Get().AddModalWindow(Window, ParentWindow, false);

	if (WindowContent->SelectedAkEventGroup.IsValid())
	{
		for (TWeakObjectPtr<UAkAudioEvent> WeakEventPtr : Objects)
		{
			if (!WeakEventPtr.IsValid()) continue;

			UAkAudioBank* Bank = Cast<UAkAudioBank>(WindowContent->SelectedAkEventGroup.GetAsset());
			if (Bank != WeakEventPtr->RequiredBank)
			{
				WeakEventPtr->LastRequiredBank = WeakEventPtr->RequiredBank;
				WeakEventPtr->RequiredBank = Bank;
				WeakEventPtr->UpdateRequiredBanks();
				WeakEventPtr->MarkPackageDirty();
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// FAssetTypeActions_AkAuxBus

void FAssetTypeActions_AkAuxBus::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	FSimpleAssetEditor::CreateEditor(EToolkitMode::Standalone, EditWithinLevelEditor, InObjects);
}

void FAssetTypeActions_AkAuxBus::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	auto AuxBusses = GetTypedWeakObjectPtrs<UAkAuxBus>(InObjects);

	MenuBuilder.AddMenuEntry(
		LOCTEXT("AkAuxBus_GroupIntoSoundBank", "Group Into Sound Bank"),
		LOCTEXT("AkAuxBus_GroupIntoSoundBankTooltip", "Group the selected aux busses into a sound bank."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateSP(this, &FAssetTypeActions_AkAuxBus::GroupIntoSoundBank, AuxBusses),
			FCanExecuteAction()
		)
	);

	FAkAssetTypeActions_ClearableBase<UAkAuxBus>::GetActions(InObjects, MenuBuilder);
}

void FAssetTypeActions_AkAuxBus::GroupIntoSoundBank(TArray<TWeakObjectPtr<UAkAuxBus>> Objects)
{
	TSharedPtr<SAkAudioBankPicker> WindowContent;

	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(LOCTEXT("WindowTitle", "Select Sound Bank"))
		.SizingRule(ESizingRule::Autosized)
		;

	Window->SetContent
	(
		SAssignNew(WindowContent, SAkAudioBankPicker)
		.WidgetWindow(Window)
	);

	TSharedPtr<SWindow> ParentWindow;

	if (FModuleManager::Get().IsModuleLoaded("MainFrame"))
	{
		IMainFrameModule& MainFrame = FModuleManager::LoadModuleChecked<IMainFrameModule>("MainFrame");
		ParentWindow = MainFrame.GetParentWindow();
	}

	FSlateApplication::Get().AddModalWindow(Window, ParentWindow, false);

	if (WindowContent->SelectedAkEventGroup.IsValid())
	{
		for (auto& weakEventPtr : Objects)
		{
			weakEventPtr->RequiredBank = Cast<UAkAudioBank>(WindowContent->SelectedAkEventGroup.GetAsset());
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// FAssetTypeActions_AkMediaAsset

FText FAssetTypeActions_AkMediaAsset::GetAssetDescription(const FAssetData& AssetData) const
{
	if (auto mediaAsset = Cast<UAkMediaAsset>(AssetData.GetAsset()))
	{
		return FText::FromString(mediaAsset->MediaName);
	}

	return FText();
}

void FAssetTypeActions_AkMediaAsset::ClearData(TArray<TWeakObjectPtr<UAkMediaAsset>> InObjects)
{
	for (const TWeakObjectPtr<UAkMediaAsset>& Asset : InObjects)
	{
		if (Asset.IsValid())
		{
			auto AssetInstance = Asset.Get();
			AssetInstance->UnloadMedia();
			AssetInstance->Reset();
		}
	}
}

void FAssetTypeActions_AkMediaAsset::GetActions(const TArray<UObject*>& InObjects,
	FMenuBuilder& MenuBuilder)
{
	FAkAssetTypeActions_Base<UAkMediaAsset>::GetActions(InObjects, MenuBuilder);
	auto AkAssets = FObjectEditorUtils::GetTypedWeakObjectPtrs<UAkMediaAsset>(InObjects);
	MenuBuilder.AddMenuEntry(
		LOCTEXT("AkAsset_ClearData", "Clear Sound Data"),
		LOCTEXT("AkAsset_ClearDataTooltip", "Clear the Sound Data serialized in the selected assets. This will not clean up .wem files associated with External Sources. To remove these so that they are properly reimported on the next Sound Data Generation, run 'Clear Sound Data > Clear the external sources cache' from the build menu."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateSP(this, &FAssetTypeActions_AkMediaAsset::ClearData, AkAssets),
			FCanExecuteAction()
		)
	);
}

//////////////////////////////////////////////////////////////////////////
// FAkAssetTypeActions_ClearableBase

template <typename AkAssetType>
void FAkAssetTypeActions_ClearableBase<AkAssetType>::GetActions(const TArray<UObject*>& InObjects,
	FMenuBuilder& MenuBuilder)
{
	FAkAssetTypeActions_Base<AkAssetType>::GetActions(InObjects, MenuBuilder);
	auto AkAssets = FObjectEditorUtils::GetTypedWeakObjectPtrs<UAkAssetBase>(InObjects);

	MenuBuilder.AddMenuEntry(
		LOCTEXT("AkAsset_ClearData", "Clear Sound Data"),
		LOCTEXT("AkAsset_ClearDataTooltip", "Clear the Sound Data serialized in the selected assets"),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateSP(this, &FAkAssetTypeActions_ClearableBase::ClearData, AkAssets),
			FCanExecuteAction()
		)
	);

	MenuBuilder.AddMenuEntry(
		LOCTEXT("AkAsset_ClearDataAndDelete", "Clear Sound Data and Delete Localized Platform Data"),
		LOCTEXT("AkAsset_ClearDataTooltip", "Clear the Sound Data serialized in the selected assets and delete the localized platform data associated with these assets"),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateSP(this, &FAkAssetTypeActions_ClearableBase::ClearDataAndDelete, AkAssets),
			FCanExecuteAction(),
			FGetActionCheckState(),
			FIsActionButtonVisible::CreateLambda([this, AkAssets]() { return CanDelete(AkAssets); })
		)
	);
}


template <typename AkAssetType>
bool FAkAssetTypeActions_ClearableBase<AkAssetType>::CanDelete(const TArray<TWeakObjectPtr<UAkAssetBase>>& InObjects)
{
	for (const TWeakObjectPtr<UAkAssetBase>& Asset : InObjects)
	{
		if (Asset.IsValid())
		{
			auto AssetInstance = Asset.Get();
			if (AssetInstance->IsLocalized())
			{
				return true;
			}
		}
	}
	return false;
}

template <typename AkAssetType>
void FAkAssetTypeActions_ClearableBase<AkAssetType>::ClearDataAndDelete(TArray<TWeakObjectPtr<UAkAssetBase>> InObjects)
{
	FAkAssetTypeActions_Helpers::ClearAssetData(InObjects, true);
}


template <typename AkAssetType>
void FAkAssetTypeActions_ClearableBase<AkAssetType>::ClearData(TArray<TWeakObjectPtr<UAkAssetBase>> InObjects)
{
	FAkAssetTypeActions_Helpers::ClearAssetData(InObjects, false);
}

#undef LOCTEXT_NAMESPACE
