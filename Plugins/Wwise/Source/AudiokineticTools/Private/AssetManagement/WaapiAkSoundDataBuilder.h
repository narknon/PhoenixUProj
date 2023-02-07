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

#include "AkSoundDataBuilder.h"

#include "Async/Future.h"
#include "Containers/UnrealString.h"

class FEvent;
class FJsonObject;
class UAkAudioEvent;
class UAkAuxBus;
class UAkInitBank;

class WaapiAkSoundDataBuilder : public AkSoundDataBuilder
{
public:
	WaapiAkSoundDataBuilder(const InitParameters& InitParameter);
	~WaapiAkSoundDataBuilder();

	void Init() override;

	void DoWork() override;

private:
	void OnSoundBankGenerated(uint64_t Id, TSharedPtr<FJsonObject> ResponseJson);
	void onSoundBankGenerationDone(uint64_t id, TSharedPtr<FJsonObject> responseJson);

	bool parseBankData(UAkAssetData* AssetData, TSharedPtr<FJsonObject> ResponseJson, FCriticalSection* DataLock);

private:
	uint64 _generatedSubscriptionId = 0;
	uint64 _generatedDoneSubscriptionId = 0;
	FDelegateHandle _connectionLostHandle;

	FEvent* waitForGenerationDoneEvent = nullptr;
	FThreadSafeBool _generationSuccess = true;
};
