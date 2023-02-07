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


#include "AkComponentCallbackManager.h"
#include "AkAudioDevice.h"
#include "AkInclude.h"
#include "Misc/ScopeLock.h"
#include "Misc/ScopeExit.h"
#include "Async/Async.h"
#include "AkCallbackInfoPool.h"
#include "AkComponent.h"

struct FAkComponentCallbackManager_Constants
{
	/// Optimization policy
	enum class Optimize
	{
		MemoryUsage,
		Speed,

		Value = MemoryUsage, ///< Set to either MemoryUsage or Speed
	};

	/// The default number of expected simultaneously playing sounds on a specific GameObject
	enum { ReserveSize = 8, };
};

FAkComponentCallbackManager* FAkComponentCallbackManager::Instance = nullptr;

FAkComponentCallbackManager* FAkComponentCallbackManager::GetInstance()
{
	return Instance;
}

void FAkFunctionPtrEventCallbackPackage::HandleAction(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo)
{
	if (pfnUserCallback)
	{
		in_pCallbackInfo->pCookie = pUserCookie;
		pfnUserCallback(in_eType, in_pCallbackInfo);
		in_pCallbackInfo->pCookie = (void*)this;
	}
}

void FAkFunctionPtrEventCallbackPackage::CancelCallback()
{
	pfnUserCallback = nullptr;
	uUserFlags = 0;
}

void FAkBlueprintDelegateEventCallbackPackage::HandleAction(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo)
{
	if (BlueprintCallback.IsBound())
	{
		AkCallbackInfo* cbInfoCopy = AkCallbackTypeHelpers::CopyWwiseCallbackInfo(in_eType, in_pCallbackInfo);
		EAkCallbackType BlueprintCallbackType = AkCallbackTypeHelpers::GetBlueprintCallbackTypeFromAkCallbackType(in_eType);
		auto CachedBlueprintCallback = BlueprintCallback;
		AsyncTask(ENamedThreads::GameThread, [cbInfoCopy, BlueprintCallbackType, CachedBlueprintCallback]
		{
			if (!cbInfoCopy)
			{
				return;
			}

			ON_SCOPE_EXIT {
				FMemory::Free(cbInfoCopy);
			};

			if (!CachedBlueprintCallback.IsBound())
			{
				return;
			}

			UAkComponent* akComponent = (UAkComponent*)cbInfoCopy->gameObjID;
			if (!akComponent->IsValidLowLevel())
			{
				return;
			}

			UAkCallbackInfo* BlueprintAkCallbackInfo = nullptr;
			if (cbInfoCopy)
			{
				BlueprintAkCallbackInfo = AkCallbackTypeHelpers::GetBlueprintableCallbackInfo(BlueprintCallbackType, cbInfoCopy);
			}
			CachedBlueprintCallback.ExecuteIfBound(BlueprintCallbackType, BlueprintAkCallbackInfo);

			if (auto AudioDevice = FAkAudioDevice::Get())
			{
				if (auto CallbackInfoPool = AudioDevice->GetAkCallbackInfoPool())
				{
					CallbackInfoPool->Release(BlueprintAkCallbackInfo);
				}
			}
		});
	}
}

void FAkBlueprintDelegateEventCallbackPackage::CancelCallback()
{
	BlueprintCallback.Clear();
	uUserFlags = 0;
}

void FAkLatentActionEventCallbackPackage::HandleAction(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo)
{
	// Don't access EndOfEventLatentAction if it's been deleted already
	if (!LatentActionValidityToken->bValid)
	{
		return;
	}

	if (EndOfEventLatentAction)
	{
		EndOfEventLatentAction->EventFinished = true;
	}
}

void FAkComponentCallbackManager::AkComponentCallback(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo)
{
	auto pPackage = (IAkUserEventCallbackPackage*)in_pCallbackInfo->pCookie;

	if (Instance && pPackage)
	{
		const auto& gameObjID = in_pCallbackInfo->gameObjID;
		bool deletePackage = false;

		{
			FScopeLock Lock(&Instance->CriticalSection);
			auto pPackageSet = Instance->GameObjectToPackagesMap.Find(gameObjID);
			if (pPackageSet && in_eType == AK_EndOfEvent)
			{
				Instance->RemovePackageFromSet(pPackageSet, pPackage, gameObjID);
			}
		}

		if (in_eType == AK_EndOfEvent)
		{
			deletePackage = true;
			if (auto* Device = FAkAudioDevice::Get())
			{
				Device->RemovePlayingID(((AkEventCallbackInfo*)in_pCallbackInfo)->eventID, ((AkEventCallbackInfo*)in_pCallbackInfo)->playingID);
				Device->CleanPinnedObjects(((AkEventCallbackInfo*)in_pCallbackInfo)->playingID);
			}
		}

		if ((pPackage->uUserFlags & in_eType) != 0)
		{
			pPackage->HandleAction(in_eType, in_pCallbackInfo);
		}
		
		if (deletePackage)
		{
			delete pPackage;
		}
	}
}

FAkComponentCallbackManager::FAkComponentCallbackManager()
{
	if (Instance != nullptr)
	{
		UE_LOG(LogInit, Error, TEXT("FAkComponentCallbackManager has already been instantiated."));
	}

	Instance = this;
}

FAkComponentCallbackManager::~FAkComponentCallbackManager()
{
	for (auto& Item : GameObjectToPackagesMap)
	{
		for (auto pPackage : Item.Value)
		{
			delete pPackage;
		}
	}

	Instance = nullptr;
}

IAkUserEventCallbackPackage* FAkComponentCallbackManager::CreateCallbackPackage(AkCallbackFunc in_cbFunc, void* in_Cookie, uint32 in_Flags, AkGameObjectID in_gameObjID)
{
	uint32 KeyHash = GetKeyHash(in_Cookie);
	auto pPackage = new FAkFunctionPtrEventCallbackPackage(in_cbFunc, in_Cookie, in_Flags, KeyHash);
	if (pPackage)
	{
		FScopeLock Lock(&CriticalSection);
		GameObjectToPackagesMap.FindOrAdd(in_gameObjID).Add(pPackage);
		UserCookieHashToPackageMap.Add(KeyHash, pPackage);
	}

	return pPackage;
}

IAkUserEventCallbackPackage* FAkComponentCallbackManager::CreateCallbackPackage(FOnAkPostEventCallback BlueprintCallback, uint32 in_Flags, AkGameObjectID in_gameObjID)
{
	uint32 KeyHash = GetKeyHash(BlueprintCallback);
	auto pPackage = new FAkBlueprintDelegateEventCallbackPackage(BlueprintCallback, in_Flags, KeyHash);
	if (pPackage)
	{
		FScopeLock Lock(&CriticalSection);
		GameObjectToPackagesMap.FindOrAdd(in_gameObjID).Add(pPackage);
		UserCookieHashToPackageMap.Add(KeyHash, pPackage);
	}

	return pPackage;
}

IAkUserEventCallbackPackage* FAkComponentCallbackManager::CreateCallbackPackage(FWaitEndOfEventAction* LatentAction, AkGameObjectID in_gameObjID)
{
	auto pPackage = new FAkLatentActionEventCallbackPackage(LatentAction, 0);
	if (pPackage)
	{
		FScopeLock Lock(&CriticalSection);
		GameObjectToPackagesMap.FindOrAdd(in_gameObjID).Add(pPackage);
	}

	return pPackage;
}

void FAkComponentCallbackManager::RemoveCallbackPackage(IAkUserEventCallbackPackage* in_Package, AkGameObjectID in_gameObjID)
{
	{
		FScopeLock Lock(&CriticalSection);
		auto pPackageSet = GameObjectToPackagesMap.Find(in_gameObjID);
		if (pPackageSet)
		{
			RemovePackageFromSet(pPackageSet, in_Package, in_gameObjID);
		}
	}

	delete in_Package;
}

void FAkComponentCallbackManager::CancelEventCallback(void* in_Cookie)
{
	CancelKeyHash(GetKeyHash(in_Cookie));
}

void FAkComponentCallbackManager::CancelEventCallback(const FOnAkPostEventCallback& in_Delegate)
{
	CancelKeyHash(GetKeyHash(in_Delegate));
}

void FAkComponentCallbackManager::CancelKeyHash(uint32 HashToCancel)
{
	FScopeLock AutoLock(&CriticalSection);

	TArray<IAkUserEventCallbackPackage*> PackagesToCancel;
	UserCookieHashToPackageMap.MultiFind(HashToCancel, PackagesToCancel);

	for (auto iter = PackagesToCancel.CreateConstIterator(); iter; ++iter)
	{
		if (*iter)
		{
			(*iter)->CancelCallback();
		}
	}
}

void FAkComponentCallbackManager::RegisterGameObject(AkGameObjectID in_gameObjID)
{
	if (FAkComponentCallbackManager_Constants::Optimize::Value == FAkComponentCallbackManager_Constants::Optimize::Speed)
	{
		FScopeLock Lock(&CriticalSection);
		GameObjectToPackagesMap.FindOrAdd(in_gameObjID).Reserve(FAkComponentCallbackManager_Constants::ReserveSize);
	}
}

void FAkComponentCallbackManager::UnregisterGameObject(AkGameObjectID in_gameObjID)
{
	// Do not cancel callbacks with the SoundEngine, as we need them for the 
	// playingID bookkeeping. Deleting the packages will ensure we do not callback
	// into objects that may have been destroyed.

	FScopeLock Lock(&CriticalSection);
	auto pPackageSet = GameObjectToPackagesMap.Find(in_gameObjID);
	if (pPackageSet)
	{
		for (auto pPackage : *pPackageSet)
		{
			pPackage->CancelCallback();
			UserCookieHashToPackageMap.Remove(pPackage->KeyHash, pPackage);
		}

		GameObjectToPackagesMap.Remove(in_gameObjID);
	}
}

bool FAkComponentCallbackManager::HasActiveEvents(AkGameObjectID in_gameObjID)
{
	FScopeLock Lock(&CriticalSection);
	auto pPackageSet = GameObjectToPackagesMap.Find(in_gameObjID);
	return pPackageSet && pPackageSet->Num() > 0;
}

void FAkComponentCallbackManager::RemovePackageFromSet(FAkComponentCallbackManager::PackageSet* in_pPackageSet, IAkUserEventCallbackPackage* in_pPackage, AkGameObjectID in_gameObjID)
{
	// No need for a lock here because those calling this function are already locking
	in_pPackageSet->Remove(in_pPackage);
	UserCookieHashToPackageMap.Remove(in_pPackage->KeyHash, in_pPackage);
	if (FAkComponentCallbackManager_Constants::Optimize::Value == FAkComponentCallbackManager_Constants::Optimize::MemoryUsage)
	{
		if (in_pPackageSet->Num() == 0)
		{
			GameObjectToPackagesMap.Remove(in_gameObjID);
		}
	}
}

uint32 FAkComponentCallbackManager::GetKeyHash(void* Key)
{
	return GetTypeHash(Key);
}

uint32 FAkComponentCallbackManager::GetKeyHash(const FOnAkPostEventCallback& Key)
{
	return HashCombine(GetTypeHash(Key.GetUObject()), GetTypeHash(Key.GetFunctionName()));
}

