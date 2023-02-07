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
	SGenerateSoundBanks.h
------------------------------------------------------------------------------------*/
#pragma once

#include "Widgets/SCompoundWidget.h"
#include "Widgets/Views/SListView.h"
#include "Widgets/Views/STableRow.h"
#include "WwiseProject/WwiseProjectInfo.h"

class SCheckBox;

class SGenerateSoundBanks : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS( SGenerateSoundBanks )
	{}
	SLATE_END_ARGS( )

	SGenerateSoundBanks(void);

	AUDIOKINETICTOOLS_API void Construct(const FArguments& InArgs);
	virtual FReply OnKeyDown( const FGeometry& MyGeometry, const FKeyEvent& InKeyboardEvent ) override;

	/** override the base method to allow for keyboard focus */
	virtual bool SupportsKeyboardFocus() const
	{
		return true;
	}

	bool ShouldDisplayWindow() { return PlatformNames.Num() != 0; }

private:
	void PopulateList();

private:
	FReply OnGenerateButtonClicked();
	TSharedRef<ITableRow> MakePlatformListItemWidget(TSharedPtr<FString> Platform, const TSharedRef<STableViewBase>& OwnerTable);

private:
	TSharedPtr<SListView<TSharedPtr<FString>>> PlatformList;
	TSharedPtr<SListView<TSharedPtr<FString>>> LanguageList;
	TSharedPtr<SCheckBox> SkipLanguagesCheckBox;

	TArray<TSharedPtr<FString>> PlatformNames;
	TArray<TSharedPtr<FString>> LanguagesNames;

	WwiseProjectInfo wwiseProjectInfo;
};