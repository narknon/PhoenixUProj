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

#include "Misc/EnumClassFlags.h"
#include "Logging/LogMacros.h"
#include "Core/Public/UObject/WeakObjectPtrTemplates.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAkSoundData, Log, All);

class UAkAudioBank;

namespace AkAudioBankGenerationHelper
{
	/**
	 * Get path to the WwiseConsole application
	 */
	FString GetWwiseConsoleApplicationPath();

	/**
	 * Function to create the Generate SoundBanks window
	 *
	 * @param pSoundBanks				List of SoundBanks to be pre-selected
	 * @paramin_bShouldSaveWwiseProject	Whether the Wwise project should be saved or not
	 */
	void CreateGenerateSoundDataWindow(TArray<TWeakObjectPtr<UAkAudioBank>>* SoundBanks = nullptr, bool ProjectSave = false);

	void CreateClearSoundDataWindow();

	enum class AkSoundDataClearFlags
	{
		None = 0,
		AssetData = 1 << 0,
		SoundBankInfoCache = 1 << 1,
		MediaCache = 1 << 2,
		OrphanMedia = 1 << 3,
		ExternalSource = 1 << 4,
		OrphanAssetData = 1 << 5,
		DeleteLocalizedPlatformData = 1 << 6
	};

	ENUM_CLASS_FLAGS(AkSoundDataClearFlags)

	void DoClearSoundData(AkSoundDataClearFlags ClearFlags);
}
