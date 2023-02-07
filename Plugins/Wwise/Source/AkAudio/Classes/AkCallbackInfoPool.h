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

#include "Engine/EngineTypes.h"
#include "CoreUObject/Public/UObject/StrongObjectPtr.h"

class UAkCallbackInfo;

class AkCallbackInfoPool final
{
public:
	template<typename CallbackType>
	CallbackType* Acquire()
	{
		return static_cast<CallbackType*>(internalAcquire(CallbackType::StaticClass()));
	}

	void Release(UAkCallbackInfo* instance);

private:
	UAkCallbackInfo* internalAcquire(UClass* type);

private:
	TMap<UClass*, TArray<UAkCallbackInfo*>> Pool;
	TArray<TStrongObjectPtr<UAkCallbackInfo>> gcStorage;
};
