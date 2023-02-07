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
	SClearSoundData.h
------------------------------------------------------------------------------------*/
#pragma once

#include "Framework/Application/SlateApplication.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/SCompoundWidget.h"

class SCheckBox;

class SClearSoundData : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS( SClearSoundData )
	{}
	SLATE_END_ARGS( )

	SClearSoundData(void);

	AUDIOKINETICTOOLS_API void Construct(const FArguments& InArgs);
	virtual FReply OnKeyDown( const FGeometry& MyGeometry, const FKeyEvent& InKeyboardEvent ) override;

	/** override the base method to allow for keyboard focus */
	virtual bool SupportsKeyboardFocus() const
	{
		return true;
	}
		

	bool GetDeleteLocalizedEnabled() const
	{
		return (ClearAssetData && ClearAssetData->IsChecked());
	}

private:
	FReply OnClearButtonClicked();

private:
	TSharedPtr<SCheckBox> ClearAssetData;
	TSharedPtr<SCheckBox> DeleteLocalizedPlatformData;
	TSharedPtr<SCheckBox> ClearSoundBankInfoCache;
	TSharedPtr<SCheckBox> ClearMediaCache;
	TSharedPtr<SCheckBox> ClearExternalSource;
	TSharedPtr<SCheckBox> ClearOrphanMedia;
	TSharedPtr<SCheckBox> ClearOrphanLocalizedAssetData;
};