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

#include "WaapiPicker/WwiseTreeItem.h"
#include "Materials/Material.h"

/**
* Implements the visual style of Wwise Picker.
*/
class AKAUDIO_API FAkAudioStyle
{
public:
	static const ISlateStyle& Get();
	static void Initialize();
	static void Shutdown();

	static void DisplayEditorMessgae(const FText& messageText, EWwiseItemType::Type wwiseItemType = EWwiseItemType::Type::None, float duration = 1.5f);

	static FName GetStyleSetName();

	static const FSlateBrush* GetWwiseIcon();
	static const FSlateBrush* GetBrush(EWwiseItemType::Type ItemType);
	static const FSlateBrush* GetBrush(FName PropertyName, const ANSICHAR* Specifier = NULL);
	static const FSlateFontInfo GetFontStyle(FName PropertyName, const ANSICHAR* Specifier = NULL);
	static UMaterial* GetAkForegroundTextMaterial();
	/** returns a color from the WwiseUnrealColorPalette (taken from the dark theme in the Wwise Authoring tool). Use a colorIndex of -1 to use the 'default' color. */
	static FLinearColor GetWwiseObjectColor(int colorIndex);
private:
	static TSharedPtr< class FSlateStyleSet > StyleInstance;
	static UMaterial* TextMaterial;
};
