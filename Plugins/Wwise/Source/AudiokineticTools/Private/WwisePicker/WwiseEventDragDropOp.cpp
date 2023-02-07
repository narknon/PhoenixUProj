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


/*------------------------------------------------------------------------------------
	WwiseEventDragDropOp.cpp
------------------------------------------------------------------------------------*/

#include "WwisePicker/WwiseEventDragDropOp.h"

#include "AkAcousticTexture.h"
#include "AkAudioEvent.h"
#include "AkAudioStyle.h"
#include "AkAuxBus.h"
#include "AkRtpc.h"
#include "AkStateValue.h"
#include "AkSwitchValue.h"
#include "AkTrigger.h"
#include "AkUnrealHelper.h"
#include "AssetToolsModule.h"
#include "ContentBrowserModule.h"
#include "Factories/AkAssetFactories.h"
#include "Factories/Factory.h"
#include "IAssetTools.h"
#include "Modules/ModuleManager.h"
#include "WaapiPicker/SWaapiPicker.h"
#include "WaapiPicker/WwiseTreeItem.h"

#define LOCTEXT_NAMESPACE "AkAudio"

TSharedRef<FWwiseEventDragDropOp> FWwiseEventDragDropOp::New(TArray<TSharedPtr<FWwiseTreeItem>> InAssets)
{
	FWwiseEventDragDropOp* RawPointer = new FWwiseEventDragDropOp();
	TSharedRef<FWwiseEventDragDropOp> Operation = MakeShareable(RawPointer);
	
	Operation->MouseCursor = EMouseCursor::GrabHandClosed;
	Operation->WwiseAssets = InAssets;
	Operation->SetCanDrop(false);

	EWwiseItemType::Type ItemType = InAssets[0]->ItemType;
	int32 i = 1;
	for (; i < InAssets.Num(); i++)
	{
		if (InAssets[i]->ItemType != ItemType)
		{
			break;
		}
	}

	if (i == InAssets.Num())
	{
		Operation->Icon = FAkAudioStyle::GetBrush(ItemType);
	}

	Operation->Construct();
	
	FAssetViewDragAndDropExtender::FOnDropDelegate DropDelegate = FAssetViewDragAndDropExtender::FOnDropDelegate::CreateRaw(RawPointer, &FWwiseEventDragDropOp::OnAssetViewDrop);
	FAssetViewDragAndDropExtender::FOnDragOverDelegate DragOverDelegate = FAssetViewDragAndDropExtender::FOnDragOverDelegate::CreateRaw(RawPointer, &FWwiseEventDragDropOp::OnAssetViewDragOver);
	FAssetViewDragAndDropExtender::FOnDragLeaveDelegate DragLeaveDelegate = FAssetViewDragAndDropExtender::FOnDragLeaveDelegate::CreateRaw(RawPointer, &FWwiseEventDragDropOp::OnAssetViewDragLeave);
	Operation->pExtender = new FAssetViewDragAndDropExtender(DropDelegate, DragOverDelegate, DragLeaveDelegate);

	FContentBrowserModule& ContentBrowserModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FAssetViewDragAndDropExtender>& AssetViewDragAndDropExtenders = ContentBrowserModule.GetAssetViewDragAndDropExtenders();
	AssetViewDragAndDropExtenders.Add(*(Operation->pExtender));
	
	return Operation;
}

FWwiseEventDragDropOp::~FWwiseEventDragDropOp()
{
	FContentBrowserModule& ContentBrowserModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FAssetViewDragAndDropExtender>& AssetViewDragAndDropExtenders = ContentBrowserModule.GetAssetViewDragAndDropExtenders();
	for (int32 i = 0; i < AssetViewDragAndDropExtenders.Num(); i++)
	{
		if (AssetViewDragAndDropExtenders[i].OnDropDelegate.IsBoundToObject(this))
		{
			AssetViewDragAndDropExtenders.RemoveAt(i);
		}
	}

	delete pExtender;
}

bool FWwiseEventDragDropOp::OnAssetViewDrop(const FAssetViewDragAndDropExtender::FPayload& Payload)
{
	if (CanDrop)
	{
		for (int32 i = 0; i < WwiseAssets.Num(); i++)
		{
			RecurseCreateAssets(WwiseAssets[i], Payload.PackagePaths[0].ToString());
		}

		return true;
	}

	return false;
}

UObject* FWwiseEventDragDropOp::RecurseCreateAssets(const TSharedPtr<FWwiseTreeItem>& Asset, const FString& PackagePath)
{
	bool isUsingNewAssetManagement = AkUnrealHelper::IsUsingEventBased();

	FString Name;
	UFactory* Factory = nullptr;
	UClass* Class = nullptr;

	if (Asset->ItemType == EWwiseItemType::Event)
	{
		Name = Asset->DisplayName;
		Factory = UAkAudioEventFactory::StaticClass()->GetDefaultObject<UFactory>();
		Class = UAkAudioEvent::StaticClass();
	}
	if (Asset->ItemType == EWwiseItemType::AcousticTexture)
	{
		Name = Asset->DisplayName;
		Factory = UAkAcousticTextureFactory::StaticClass()->GetDefaultObject<UFactory>();
		Class = UAkAcousticTexture::StaticClass();
	}
	else if (Asset->ItemType == EWwiseItemType::AuxBus)
	{
		Name = Asset->DisplayName;
		Factory = UAkAuxBusFactory::StaticClass()->GetDefaultObject<UFactory>();
		Class = UAkAuxBus::StaticClass();
		for (TSharedPtr<FWwiseTreeItem> Child : Asset->GetChildren())
		{
			RecurseCreateAssets(Child, PackagePath + "/" + Name);
		}
	}
	else if (isUsingNewAssetManagement && Asset->ItemType == EWwiseItemType::GameParameter)
	{
		Name = Asset->DisplayName;
		Factory = UAkRtpcFactory::StaticClass()->GetDefaultObject<UFactory>();
		Class = UAkRtpc::StaticClass();
	}
	else if (isUsingNewAssetManagement && Asset->ItemType == EWwiseItemType::State)
	{
		Name = FString::Printf(TEXT("%s-%s"), *Asset->Parent.Pin()->DisplayName, *Asset->DisplayName);
		Factory = UAkStateValueFactory::StaticClass()->GetDefaultObject<UFactory>();
		Class = UAkStateValue::StaticClass();
	}
	else if (isUsingNewAssetManagement && Asset->ItemType == EWwiseItemType::Switch)
	{
		Name = FString::Printf(TEXT("%s-%s"), *Asset->Parent.Pin()->DisplayName, *Asset->DisplayName);
		Factory = UAkSwitchValueFactory::StaticClass()->GetDefaultObject<UFactory>();
		Class = UAkSwitchValue::StaticClass();
	}
	else if (isUsingNewAssetManagement && Asset->ItemType == EWwiseItemType::Trigger)
	{
		Name = Asset->DisplayName;
		Factory = UAkTriggerFactory::StaticClass()->GetDefaultObject<UFactory>();
		Class = UAkTrigger::StaticClass();
	}
	else if (Asset->IsOfType({ EWwiseItemType::Bus, EWwiseItemType::StandaloneWorkUnit, EWwiseItemType::NestedWorkUnit, EWwiseItemType::Folder, EWwiseItemType::PhysicalFolder }))
	{
		for (TSharedPtr<FWwiseTreeItem> Child : Asset->GetChildren())
		{
			RecurseCreateAssets(Child, PackagePath + "/" + Asset->DisplayName);
		}
	}

	if (Factory)
	{
		FString Path = PackagePath;

		// UE5 adds "/All" to all game content folder paths, but CreateAsset doesn't like it
		Path.RemoveFromStart(TEXT("/All"));

		// UE5 adds "/All/Plugins" to all plugin content folder paths, but CreateAsset doesn't like it
		Path.RemoveFromStart(TEXT("/Plugins"));

		if (auto akFactory = Cast<UAkAssetFactory>(Factory))
		{
			akFactory->AssetID = Asset->ItemId;
		}

		TCHAR CharString[] = { '\0', '\0' };
		for (const TCHAR* InvalidCharacters = INVALID_LONGPACKAGE_CHARACTERS; *InvalidCharacters; ++InvalidCharacters)
		{
			CharString[0] = *InvalidCharacters;
			Path.ReplaceInline(CharString, TEXT(""));
		}

		FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked< FAssetToolsModule >("AssetTools");
		return AssetToolsModule.Get().CreateAsset(Name, Path, Class, Factory);
	}

	return nullptr;
}

bool FWwiseEventDragDropOp::OnAssetViewDragOver(const FAssetViewDragAndDropExtender::FPayload& Payload)
{
	SetCanDrop(true);
	return true;
}

bool FWwiseEventDragDropOp::OnAssetViewDragLeave(const FAssetViewDragAndDropExtender::FPayload& Payload)
{
	SetCanDrop(false);
	return true;
}

void FWwiseEventDragDropOp::SetCanDrop(const bool InCanDrop)
{
	CanDrop = InCanDrop;
	SetTooltipText();
	if( InCanDrop )
	{
		MouseCursor = EMouseCursor::GrabHandClosed;
		SetToolTip(GetTooltipText(), NULL);
	}
	else
	{
		MouseCursor = EMouseCursor::SlashedCircle;
		SetToolTip(GetTooltipText(), FEditorStyle::GetBrush(TEXT("Graph.ConnectorFeedback.Error")));
	}
}

FCursorReply FWwiseEventDragDropOp::OnCursorQuery()
{
	return FCursorReply::Unhandled();
}

void FWwiseEventDragDropOp::SetTooltipText()
{
	if( CanDrop )
	{
		FString Text = (WwiseAssets.Num() && WwiseAssets[0].IsValid())? WwiseAssets[0]->DisplayName : TEXT("");

		if (WwiseAssets.Num() > 1 )
		{
			Text += TEXT(" ");
			Text += FString::Printf(TEXT("and %d other(s)"), WwiseAssets.Num() - 1);
		}
		CurrentHoverText = FText::FromString(Text);
	}
	else
	{
		CurrentHoverText = LOCTEXT("OnDragAkEventsOverFolder_CannotDrop", "Wwise assets can only be dropped in the content browser");
	}
}

FText FWwiseEventDragDropOp::GetTooltipText() const
{
	return CurrentHoverText;
}

TSharedPtr<SWidget> FWwiseEventDragDropOp::GetDefaultDecorator() const
{
	return 
		SNew(SBorder)
		.BorderImage(FEditorStyle::GetBrush("ContentBrowser.AssetDragDropTooltipBackground"))
		.Content()
		[
			SNew(SHorizontalBox)

			// Left slot is folder icon
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			[
				SNew(SImage)
				.Image(Icon)
			]

			// Right slot is for tooltip
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(3.0f)
				.VAlign(VAlign_Center)
				[
					SNew(SImage) 
					.Image(this, &FWwiseEventDragDropOp::GetIcon)
				]

				+SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(0,0,3,0)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock) 
					.Text(this, &FWwiseEventDragDropOp::GetTooltipText)
				]
			]
		];
}

const TArray< TSharedPtr<FWwiseTreeItem> > & FWwiseEventDragDropOp::GetWiseItems() const
{
	return WwiseAssets;
}

#undef LOCTEXT_NAMESPACE
