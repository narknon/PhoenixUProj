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
	SWaapiPickerRow.cpp
------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------
 includes.
------------------------------------------------------------------------------------*/
#include "WaapiPicker/SWaapiPickerRow.h"
#include "AkAudioDevice.h"
#include "AkWaapiUtils.h"
#include "WaapiPicker/SWaapiPicker.h"
#include "Widgets/Input/SSearchBox.h"
#include "AkAudioStyle.h"
#include "Widgets/Images/SImage.h"

/*------------------------------------------------------------------------------------
Defines
------------------------------------------------------------------------------------*/
#define LOCTEXT_NAMESPACE "AkAudio"


bool SWaapiPickerRow::CallWaapiExecuteUri(const char* inUri, const TArray<KeyValueArgs>& values, TSharedPtr<FJsonObject>& outJsonResult)
{
	TSharedRef<FJsonObject> args = MakeShareable(new FJsonObject());

	for (auto value : values)
	{
		args->SetStringField(value.keyArg, value.valueArg);
	}

	// Construct the options Json object;
	TSharedRef<FJsonObject> options = MakeShareable(new FJsonObject());

	// Connect to Wwise Authoring on localhost.
	FAkWaapiClient* waapiClient = FAkWaapiClient::Get();
	if (waapiClient)
	{
		// Request infos/changes in Waapi Picker using WAAPI
		if (waapiClient->Call(inUri, args, options, outJsonResult))
		{
			return true;
		}
		else
		{
			UE_LOG(LogAkAudioPicker, Log, TEXT("Call Failed"));
		}
	}
	else
	{
		UE_LOG(LogAkAudioPicker, Log, TEXT("Unable to connect to localhost"));
	}
	return false;
}

/*------------------------------------------------------------------------------------
Implementation
------------------------------------------------------------------------------------*/
void SWaapiPickerRow::Construct(const FArguments& InArgs)
{
	ParentWidget = InArgs._ParentWidget;
	WaapiPickerItem = InArgs._WaapiPickerItem;

	bool bIsRoot = !WaapiPickerItem.Pin()->Parent.IsValid() && 
					((WaapiPickerItem.Pin()->FolderPath == WwiseWaapiHelper::BACK_SLASH + EWwiseItemType::FolderNames[EWwiseItemType::Event])	  || 
					(WaapiPickerItem.Pin()->FolderPath == WwiseWaapiHelper::BACK_SLASH + EWwiseItemType::FolderNames[EWwiseItemType::AuxBus])	  || 
					(WaapiPickerItem.Pin()->FolderPath == WwiseWaapiHelper::BACK_SLASH + EWwiseItemType::FolderNames[EWwiseItemType::ActorMixer]) ||
					(WaapiPickerItem.Pin()->FolderPath == WwiseWaapiHelper::BACK_SLASH + EWwiseItemType::FolderNames[EWwiseItemType::AcousticTexture]));

	ChildSlot
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(0, bIsRoot? 2 : 1, 2, 1)
		.VAlign(VAlign_Center)
		[
			// Item Icon
			SNew(SImage)
			.Image(FAkAudioStyle::GetBrush(WaapiPickerItem.Pin()->ItemType))
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		[
			SAssignNew(InlineRenameWidget, SInlineEditableTextBlock)
			.Text(this, &SWaapiPickerRow::GetNameText)
			.ToolTipText(this, &SWaapiPickerRow::GetToolTipText)
			.Font(FAkAudioStyle::GetFontStyle(bIsRoot ? "AudiokineticTools.SourceTreeRootItemFont" : "AudiokineticTools.SourceTreeItemFont"))
			.HighlightText(InArgs._HighlightText)
			.OnTextCommitted(this, &SWaapiPickerRow::HandleNameCommitted)
			.OnVerifyTextChanged(this, &SWaapiPickerRow::HandleVerifyNameChanged)
			.IsSelected(InArgs._IsSelected)
			.IsReadOnly(this, &SWaapiPickerRow::IsWiseItemNameReadOnly)
		]
	];

	if (InlineRenameWidget.IsValid())
	{
		EnterEditingModeDelegateHandle = OnRenamedRequestEvent.AddSP(InlineRenameWidget.Get(), &SInlineEditableTextBlock::EnterEditingMode);
	}
}

void SWaapiPickerRow::EnterEditingMode()
{
	InlineRenameWidget->EnterEditingMode();
}

SWaapiPickerRow::~SWaapiPickerRow()
{
	if (InlineRenameWidget.IsValid())
	{
		OnRenamedRequestEvent.Remove(EnterEditingModeDelegateHandle);
	}
}

void SWaapiPickerRow::HandleNameCommitted(const FText& NewText, ETextCommit::Type CommitInfo)
{
	TSharedPtr<FWwiseTreeItem> WaapiPickerItemPtr = WaapiPickerItem.Pin();

	if (WaapiPickerItemPtr.IsValid())
	{
		FText WarningMessage;
		const bool bIsCommitted = (CommitInfo != ETextCommit::OnCleared);
		if (!OnItemRenameCommitted(WaapiPickerItemPtr, NewText.ToString(), WarningMessage) && ParentWidget.IsValid() && bIsCommitted)
		{
			// Failed to rename/create a WaapiPickerItem, display a warning.
			UE_LOG(LogAkAudioPicker, Log, TEXT("Rename Failed : %s"), *WarningMessage.ToString());
		}
	}
}

bool SWaapiPickerRow::OnItemRenameCommitted(const TSharedPtr< FWwiseTreeItem >& WwiseItem, const FString& InNewItemName, FText& OutWarningMessage)
{
	if (WwiseItem.IsValid() && !InNewItemName.Equals(WwiseItem->DisplayName, ESearchCase::CaseSensitive))
	{
		const FGuid& in_ItemId = WwiseItem->ItemId;
		const FString itemIdStringField = in_ItemId.ToString(EGuidFormats::DigitsWithHyphensInBraces);
		TSharedPtr<FJsonObject> getResult;
		if (CallWaapiExecuteUri(ak::wwise::core::object::setName, { {WwiseWaapiHelper::OBJECT, itemIdStringField} , {WwiseWaapiHelper::VALUE, InNewItemName } }, getResult))
		{
			return true;
		}
	}
	return false;
}

bool SWaapiPickerRow::HandleVerifyNameChanged(const FText& NewText, FText& OutErrorMessage)
{
	TSharedPtr<FWwiseTreeItem> WaapiPickerItemPtr = WaapiPickerItem.Pin();

	if (WaapiPickerItemPtr.IsValid())
	{
		return OnVerifyItemNameChanged(WaapiPickerItemPtr, NewText.ToString(), OutErrorMessage);
	}

	return false;
}

bool SWaapiPickerRow::OnVerifyItemNameChanged(const TSharedPtr< FWwiseTreeItem >& WwiseItem, const FString& InNewItemName, FText& OutErrorMessage)
{
	if (!WwiseItem.IsValid())
	{
		OutErrorMessage = LOCTEXT("RenameFailed_TreeItemDeleted", "Tree item no longer exists");
		return false;
	}

	if ((WwiseItem->ItemType == EWwiseItemType::PhysicalFolder) || (WwiseItem->ItemType == EWwiseItemType::StandaloneWorkUnit) || (WwiseItem->ItemType == EWwiseItemType::NestedWorkUnit))
	{
		OutErrorMessage = LOCTEXT("RenameFailed_WorkUnitItem", "You can't change the name of a PhysicalFolder/WorkUnit");
		return false;
	}

	if (WwiseItem->Parent == NULL)
	{
		OutErrorMessage = LOCTEXT("RenameFailed_RootTreeItem", "A root tree item can not be renamed");
		return false;
	}

	FText TrimmedLabel = FText::TrimPrecedingAndTrailing(FText::FromString(InNewItemName));

	if (TrimmedLabel.IsEmpty())
	{
		OutErrorMessage = LOCTEXT("RenameFailed_LeftBlank", "Names cannot be left blank");
		return false;
	}

	if (TrimmedLabel.ToString().Len() >= NAME_SIZE)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("CharCount"), NAME_SIZE);
		OutErrorMessage = FText::Format(LOCTEXT("RenameFailed_TooLong", "Names must be less than {CharCount} characters long."), Arguments);
		return false;
	}

	// If the new name is the same as the old name, consider this to be unchanged, and accept it.
	const FString& LabelString = TrimmedLabel.ToString();
	if (WwiseItem->DisplayName == LabelString)
	{
		return true;
	}

	int32 Dummy = 0;
	if (LabelString.FindChar('/', Dummy) || LabelString.FindChar('\\', Dummy))
	{
		OutErrorMessage = LOCTEXT("RenameFailed_InvalidChar", "Item names cannot contain / or \\.");
		return false;
	}

	// Validate that this folder doesn't exist already
	FName NewPath = FName(*(WwiseItem->Parent.Pin()->FolderPath));
	NewPath = FName(*(NewPath.ToString() + WwiseWaapiHelper::BACK_SLASH + LabelString));


	if (WwiseItem->Parent.Pin()->GetChild(InNewItemName).IsValid())
	{
		OutErrorMessage = LOCTEXT("RenameFailed_AlreadyExists", "An item with this name already exists at this level");
		return false;
	}
	return true;
}

bool SWaapiPickerRow::IsWiseItemNameReadOnly() const
{
	// We can't rename roots or Wise items of type "PhysicalFolder || StandaloneWorkUnit || NestedWorkUnit"
	const TSharedPtr<FWwiseTreeItem>& WaapiPickerItemPtr = WaapiPickerItem.Pin();
	return ((WaapiPickerItemPtr->Parent == NULL) || (WaapiPickerItemPtr->ItemType == EWwiseItemType::PhysicalFolder) || (WaapiPickerItemPtr->ItemType == EWwiseItemType::StandaloneWorkUnit) || (WaapiPickerItemPtr->ItemType == EWwiseItemType::NestedWorkUnit));
}

FText SWaapiPickerRow::GetNameText() const
{
	const TSharedPtr<FWwiseTreeItem>& WaapiPickerItemPtr = WaapiPickerItem.Pin();

	if (WaapiPickerItemPtr.IsValid())
	{
		return FText::FromString(WaapiPickerItemPtr->DisplayName);
	}
	else
	{
		return FText();
	}
}

FText SWaapiPickerRow::GetToolTipText() const
{
	const TSharedPtr<FWwiseTreeItem>& WaapiPickerItemPtr = WaapiPickerItem.Pin();

	if (WaapiPickerItemPtr.IsValid())
	{
		return FText::FromString(WaapiPickerItemPtr->FolderPath);
	}
	else
	{
		return FText();
	}
}

#undef LOCTEXT_NAMESPACE