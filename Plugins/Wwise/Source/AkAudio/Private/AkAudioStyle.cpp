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


#include "AkAudioStyle.h"
#include "AkAudioDevice.h"
#include "Framework/Notifications/NotificationManager.h"
#include "WaapiPicker/WwiseTreeItem.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Engine/Texture2D.h"
#include "Widgets/Notifications/SNotificationList.h"

TSharedPtr< FSlateStyleSet > FAkAudioStyle::StyleInstance = nullptr;
UMaterial* FAkAudioStyle::TextMaterial = nullptr;

/* Taken from the Wwise Authoring dark theme. @TODO: Take this from the theme's main.json file. */
TArray<FLinearColor> WwiseUnrealColorPalette = {
	FColor(191, 191, 191, 255),
	FColor(82, 90, 255, 1),
	FColor(41, 169, 255, 1),
	FColor(0, 255, 255, 1),
	FColor(0, 255, 0, 1),
	FColor(183, 255, 0, 1),
	FColor(255, 238, 0, 1),
	FColor(255, 170, 0, 1),
	FColor(255, 128, 0, 1),
	FColor(255, 85, 0, 1),
	FColor(255, 0, 0, 1),
	FColor(255, 0, 255, 1),
	FColor(190, 61, 255, 1),
	FColor(184, 107, 255, 1),
	FColor(112, 119, 255, 1),
	FColor(119, 164, 253, 1),
	FColor(132, 240, 240, 1),
	FColor(136, 242, 136, 1),
	FColor(209, 240, 122, 1),
	FColor(240, 192, 96, 1),
	FColor(255, 179, 102, 1),
	FColor(240, 192, 96, 1),
	FColor(255, 179, 102, 1),
	FColor(255, 146, 92, 1),
	FColor(255, 112, 255, 1),
	FColor(214, 133, 255, 1),
	FColor(166, 128, 255, 1),
	FColor(191, 191, 191, 1)
};

namespace AkAudioStyle_Helpers
{
	template<typename T1, typename T2>
	auto LoadAkTexture(T1&& RelativePath, T2&& TextureName)
	{
		return LoadObject<UTexture2D>(nullptr, *(FString("/Wwise/") / FString(Forward<T1>(RelativePath)) / FString(Forward<T2>(TextureName)) + FString(".") + FString(Forward<T2>(TextureName))));
	}

	UMaterial* LoadAkMaterial(const FString& RelativePath, const FString& MaterialName)
	{
		return LoadObject<UMaterial>(nullptr, *(FString("/Wwise/") + RelativePath + MaterialName + FString(".") + MaterialName));
	}

	auto CreateAkImageBrush(UTexture2D* Texture, const FVector2D& TextureSize)
	{
		return new FSlateImageBrush(Texture, TextureSize);
	}

	template<typename StringType, typename...Args>
	auto CreateEngineBoxBrush(FSlateStyleSet& Style, StringType& RelativePath, Args&&... args)
	{
		return new FSlateBoxBrush(Style.RootToContentDir(Forward<StringType>(RelativePath), TEXT(".png")), Forward<Args>(args)...);
	}

	template<typename StringType, typename...Args>
	auto EngineBoxBrush(FSlateStyleSet& Style, StringType&& RelativePath, Args&&... args)
	{
		return FSlateBoxBrush(Style.RootToContentDir(Forward<StringType>(RelativePath), TEXT(".png")), Forward<Args>(args)...);
	}

	template<typename StringType, typename...Args>
	auto CreateEngineImageBrush(FSlateStyleSet& Style, StringType& RelativePath, Args&&... args)
	{
		return new FSlateImageBrush(Style.RootToContentDir(Forward<StringType>(RelativePath), TEXT(".png")), Forward<Args>(args)...);
	}
}

void SetAkBrush(FSlateStyleSet& Style, const char* BrushName, const char* TextureName)
{
	using namespace AkAudioStyle_Helpers;

	const FVector2D Icon15x15(15.0f, 15.0f);

	auto Texture = LoadAkTexture("WwiseTree/Icons", TextureName);
	if (Texture != nullptr)
	{
		Texture->AddToRoot();
		Style.Set(BrushName, CreateAkImageBrush(Texture, Icon15x15));
	}
}

void SetClassThumbnail(FSlateStyleSet& Style, const char* BrushName, const char* TextureName)
{
	using namespace AkAudioStyle_Helpers;

	const FVector2D ThumbnailSize(256.0f, 256.0f);

	auto Texture = LoadAkTexture("WwiseTypes", TextureName);
	if (Texture != nullptr)
	{
		Texture->AddToRoot();
		Style.Set(BrushName, CreateAkImageBrush(Texture, ThumbnailSize));
	}
}

void SetClassIcon(FSlateStyleSet& Style, const char* BrushName, const char* TextureName)
{
	using namespace AkAudioStyle_Helpers;

	const FVector2D ThumbnailSize(15.0f, 15.0f);

	auto Texture = LoadAkTexture("WwiseTypes", TextureName);
	if (Texture != nullptr)
	{
		Texture->AddToRoot();
		Style.Set(BrushName, CreateAkImageBrush(Texture, ThumbnailSize));
	}
}

void SetAkResourceBrushes(FSlateStyleSet& Style)
{
	SetAkBrush(Style, "AudiokineticTools.WwiseIcon", "Titlebar_WwiseAppIcon");

	SetAkBrush(Style, "AudiokineticTools.ActorMixerIcon", "actor_mixer_nor");
	SetAkBrush(Style, "AudiokineticTools.SoundIcon", "sound_fx_nor");
	SetAkBrush(Style, "AudiokineticTools.SwitchContainerIcon", "container_switch_nor");
	SetAkBrush(Style, "AudiokineticTools.RandomSequenceContainerIcon", "container_random_sequence_nor");
	SetAkBrush(Style, "AudiokineticTools.BlendContainerIcon", "layer_container_nor");
	SetAkBrush(Style, "AudiokineticTools.MotionBusIcon", "motion_bus_nor");
	SetAkBrush(Style, "AudiokineticTools.AkPickerTabIcon", "wwise_logo_32");
	SetAkBrush(Style, "AudiokineticTools.EventIcon", "event_nor");
	SetAkBrush(Style, "AudiokineticTools.AcousticTextureIcon", "acoutex_nor");
	SetAkBrush(Style, "AudiokineticTools.AuxBusIcon", "auxbus_nor");
	SetAkBrush(Style, "AudiokineticTools.BusIcon", "bus_nor");
	SetAkBrush(Style, "AudiokineticTools.FolderIcon", "folder_nor");
	SetAkBrush(Style, "AudiokineticTools.PhysicalFolderIcon", "physical_folder_nor");
	SetAkBrush(Style, "AudiokineticTools.WorkUnitIcon", "workunit_nor");
	SetAkBrush(Style, "AudiokineticTools.ProjectIcon", "wproj");
	SetAkBrush(Style, "AudiokineticTools.RTPCIcon", "gameparameter_nor");
	SetAkBrush(Style, "AudiokineticTools.StateIcon", "state_nor");
	SetAkBrush(Style, "AudiokineticTools.StateGroupIcon", "stategroup_nor");
	SetAkBrush(Style, "AudiokineticTools.SwitchIcon", "switch_nor");
	SetAkBrush(Style, "AudiokineticTools.SwitchGroupIcon", "switchgroup_nor");
	SetAkBrush(Style, "AudiokineticTools.TriggerIcon", "trigger_nor");

	SetClassThumbnail(Style, "ClassThumbnail.AkAcousticTexture", "AkAcousticTexture");
	SetClassThumbnail(Style, "ClassThumbnail.AkAudioEvent", "AkAudioEvent");
	SetClassThumbnail(Style, "ClassThumbnail.AkAuxBus", "AkAuxBus");
	SetClassThumbnail(Style, "ClassThumbnail.AkAudioBank", "AkAudioBank");
	SetClassThumbnail(Style, "ClassThumbnail.AkInitBank", "AkAudioBank");
	SetClassThumbnail(Style, "ClassThumbnail.AkLocalizedMediaAsset", "AkLocalizedMediaAsset");
	SetClassThumbnail(Style, "ClassThumbnail.AkMediaAsset", "AkMediaAsset");
	SetClassThumbnail(Style, "ClassThumbnail.AkExternalMediaAsset", "AkExternalMediaAsset");
	SetClassThumbnail(Style, "ClassThumbnail.AkRtpc", "AkRtpc");
	SetClassThumbnail(Style, "ClassThumbnail.AkStateValue", "AkStateValue");
	SetClassThumbnail(Style, "ClassThumbnail.AkSwitchValue", "AkSwitchValue");
	SetClassThumbnail(Style, "ClassThumbnail.AkTrigger", "AkTrigger");

	SetClassThumbnail(Style, "ClassThumbnail.AkAcousticPortal", "AK_Acoustic_Portal");
	SetClassIcon(Style, "ClassIcon.AkAcousticPortal", "AK_Acoustic_Portal_Explorer");
	SetClassThumbnail(Style, "ClassThumbnail.AkSpatialAudioVolume", "AK_Spatial_Audio_Volume");
	SetClassIcon(Style, "ClassIcon.AkSpatialAudioVolume", "AK_Spatial_Audio_Volume_Explorer");
	SetClassThumbnail(Style, "ClassThumbnail.AkReverbVolume", "AK_Reverb_Volume");
	SetClassIcon(Style, "ClassIcon.AkReverbVolume", "AK_Reverb_Volume_Explorer");
}

void FAkAudioStyle::Initialize()
{
	using namespace AkAudioStyle_Helpers;

	if (!StyleInstance.IsValid())
	{
		StyleInstance = MakeShareable(new FSlateStyleSet(FAkAudioStyle::GetStyleSetName()));
		auto ContentRoot = FPaths::EngineContentDir() / TEXT("Slate");
		StyleInstance->SetContentRoot(ContentRoot);
		StyleInstance->SetCoreContentRoot(ContentRoot);

		FSlateStyleSet& Style = *StyleInstance.Get();
		{
			SetAkResourceBrushes(Style);

			Style.Set("AudiokineticTools.GroupBorder", CreateEngineBoxBrush(Style, "Common/GroupBorder", FMargin(4.0f / 16.0f)));
			Style.Set("AudiokineticTools.AssetDragDropTooltipBackground", CreateEngineBoxBrush(Style, "Old/Menu_Background", FMargin(8.0f / 64.0f)));

			FButtonStyle HoverHintOnly = FButtonStyle()
				.SetNormal(FSlateNoResource())
				.SetHovered(EngineBoxBrush(Style, "Common/Button_Hovered", FMargin(4 / 16.0f), FLinearColor(1, 1, 1, 0.15f)))
				.SetPressed(EngineBoxBrush(Style, "Common/Button_Pressed", FMargin(4 / 16.0f), FLinearColor(1, 1, 1, 0.25f)))
				.SetNormalPadding(FMargin(0, 0, 0, 1))
				.SetPressedPadding(FMargin(0, 1, 0, 0));
			Style.Set("AudiokineticTools.HoverHintOnly", HoverHintOnly);

			Style.Set("AudiokineticTools.SourceTitleFont", FCoreStyle::GetDefaultFontStyle("Regular", 12));
			Style.Set("AudiokineticTools.SourceTreeItemFont", FCoreStyle::GetDefaultFontStyle("Regular", 10));
			Style.Set("AudiokineticTools.SourceTreeRootItemFont", FCoreStyle::GetDefaultFontStyle("Regular", 12));

			const FVector2D Icon12x12(12.0f, 12.0f);
			Style.Set("AudiokineticTools.Button_EllipsisIcon", CreateEngineImageBrush(Style, "Icons/ellipsis_12x", Icon12x12));
		}

		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}
#undef IMAGE_BRUSH

void FAkAudioStyle::Shutdown()
{
    if (StyleInstance.IsValid())
    {
        FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
        ensure(StyleInstance.IsUnique());
        StyleInstance.Reset();
    }
}

void FAkAudioStyle::DisplayEditorMessgae(const FText& messageText, EWwiseItemType::Type wwiseItemType /* = EWwiseItemType::Type::None*/, float duration /* = 1.5f */)
{
	FNotificationInfo Info(messageText);
	if (wwiseItemType == EWwiseItemType::None)
		Info.Image = FAkAudioStyle::GetWwiseIcon();
	else
		Info.Image = FAkAudioStyle::GetBrush(wwiseItemType);
	Info.FadeInDuration = 0.1f;
	Info.FadeOutDuration = 0.5f;
	Info.ExpireDuration = duration;
	Info.bUseThrobber = false;
	Info.bUseSuccessFailIcons = false;
	Info.bUseLargeFont = true;
	Info.bFireAndForget = false;
	Info.bAllowThrottleWhenFrameRateIsLow = false;
	auto NotificationItem = FSlateNotificationManager::Get().AddNotification(Info);
	NotificationItem->SetCompletionState(SNotificationItem::CS_None);
	NotificationItem->ExpireAndFadeout();
}

FName FAkAudioStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("AudiokineticToolsStyle"));
	return StyleSetName;
}

const ISlateStyle& FAkAudioStyle::Get()
{
	Initialize();
	return *StyleInstance;
}

const FSlateBrush* FAkAudioStyle::GetWwiseIcon()
{
	auto& Style = Get();
	return Style.GetBrush("AudiokineticTools.WwiseIcon");
}

const FSlateBrush* FAkAudioStyle::GetBrush(EWwiseItemType::Type ItemType)
{
	auto& Style = Get();
	switch (ItemType)
	{
	case EWwiseItemType::Event: return Style.GetBrush("AudiokineticTools.EventIcon");
	case EWwiseItemType::AcousticTexture: return Style.GetBrush("AudiokineticTools.AcousticTextureIcon");
	case EWwiseItemType::AuxBus: return Style.GetBrush("AudiokineticTools.AuxBusIcon");
	case EWwiseItemType::Bus: return Style.GetBrush("AudiokineticTools.BusIcon");
	case EWwiseItemType::Folder: return Style.GetBrush("AudiokineticTools.FolderIcon");
	case EWwiseItemType::Project: return Style.GetBrush("AudiokineticTools.ProjectIcon");
	case EWwiseItemType::PhysicalFolder: return Style.GetBrush("AudiokineticTools.PhysicalFolderIcon");
	case EWwiseItemType::StandaloneWorkUnit:
	case EWwiseItemType::NestedWorkUnit: return Style.GetBrush("AudiokineticTools.WorkUnitIcon");
	case EWwiseItemType::ActorMixer: return Style.GetBrush("AudiokineticTools.ActorMixerIcon");
	case EWwiseItemType::Sound: return Style.GetBrush("AudiokineticTools.SoundIcon");
	case EWwiseItemType::SwitchContainer: return Style.GetBrush("AudiokineticTools.SwitchContainerIcon");
	case EWwiseItemType::RandomSequenceContainer: return Style.GetBrush("AudiokineticTools.RandomSequenceContainerIcon");
	case EWwiseItemType::BlendContainer: return Style.GetBrush("AudiokineticTools.BlendContainerIcon");
	case EWwiseItemType::MotionBus: return Style.GetBrush("AudiokineticTools.MotionBusIcon");
	case EWwiseItemType::GameParameter: return Style.GetBrush("AudiokineticTools.RTPCIcon");
	case EWwiseItemType::State: return Style.GetBrush("AudiokineticTools.StateIcon");
	case EWwiseItemType::StateGroup: return Style.GetBrush("AudiokineticTools.StateGroupIcon");
	case EWwiseItemType::Switch: return Style.GetBrush("AudiokineticTools.SwitchIcon");
	case EWwiseItemType::SwitchGroup: return Style.GetBrush("AudiokineticTools.SwitchGroupIcon");
	case EWwiseItemType::Trigger: return Style.GetBrush("AudiokineticTools.TriggerIcon");
	default:
		return nullptr;
	}
}

const FSlateBrush* FAkAudioStyle::GetBrush(FName PropertyName, const ANSICHAR* Specifier)
{
	return Get().GetBrush(PropertyName, Specifier);
}

const FSlateFontInfo FAkAudioStyle::GetFontStyle(FName PropertyName, const ANSICHAR* Specifier)
{
	return Get().GetFontStyle(PropertyName, Specifier);
}

UMaterial* FAkAudioStyle::GetAkForegroundTextMaterial()
{
	if (TextMaterial == nullptr)
	{
		TextMaterial = AkAudioStyle_Helpers::LoadAkMaterial(FString(""), FString("DefaultForegroundTextMaterial"));
		if (TextMaterial != nullptr)
			TextMaterial->AddToRoot();
	}

	return TextMaterial;
}

FLinearColor FAkAudioStyle::GetWwiseObjectColor(int colorIndex)
{
	if (WwiseUnrealColorPalette.Num() > 0)
	{
		if (colorIndex == -1)
			colorIndex = WwiseUnrealColorPalette.Num() - 1;
		if (colorIndex < WwiseUnrealColorPalette.Num())
		{
			return WwiseUnrealColorPalette[colorIndex];
		}
	}
	return FLinearColor();
}