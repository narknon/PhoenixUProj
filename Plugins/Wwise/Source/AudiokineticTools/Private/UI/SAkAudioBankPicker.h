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

#pragma once

#include "Framework/Application/SlateApplication.h"
#include "Widgets/SCompoundWidget.h"

#include "AssetData.h"

class SWindow;

class SAkAudioBankPicker : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAkAudioBankPicker)
	{}
		SLATE_ARGUMENT(TSharedPtr<SWindow>, WidgetWindow)
	SLATE_END_ARGS()

	SAkAudioBankPicker(void);

	AUDIOKINETICTOOLS_API void Construct(const FArguments& InArgs);

	FAssetData SelectedAkEventGroup;

private:
	void OnCreateNewAssetSelected();
	void OnAssetSelected(const FAssetData& AssetData);
	void OnAssetDoubleClicked(const FAssetData& AssetData);
	void OnAssetEnterPressed(const TArray<FAssetData>& AssetData);
	bool CanSelect() const;

	FReply CloseWindow();
	FReply OnCancel();

private:
	TWeakPtr<SWindow> WidgetWindow;
};