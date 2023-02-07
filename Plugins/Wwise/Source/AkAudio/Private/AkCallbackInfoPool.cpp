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

#include "AkCallbackInfoPool.h"
#include "AkGameplayTypes.h"

UAkCallbackInfo* AkCallbackInfoPool::internalAcquire(UClass* type)
{
	ensure(IsInGameThread());
	auto& poolArray = Pool.FindOrAdd(type);
	if (poolArray.Num() > 0)
	{
		return poolArray.Pop();
	}

	auto instance = NewObject<UAkCallbackInfo>(GetTransientPackage(), type, NAME_None, RF_Public | RF_Standalone);
	gcStorage.Emplace(instance);
	return instance;
}

void AkCallbackInfoPool::Release(UAkCallbackInfo* instance)
{
	ensure(IsInGameThread());
	if (Pool.Contains(instance->GetClass()))
	{
		instance->Reset();
		Pool[instance->GetClass()].Push(instance);
	}
}
