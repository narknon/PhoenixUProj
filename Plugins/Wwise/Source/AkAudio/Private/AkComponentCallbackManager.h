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

#include "AkAudioDevice.h"


class IAkUserEventCallbackPackage
{
public:
	/** Copy of the user callback flags, for use in our own callback */
	uint32 uUserFlags;

	uint32 KeyHash;

	IAkUserEventCallbackPackage()
		: uUserFlags(0)
	{}

	IAkUserEventCallbackPackage(uint32 in_Flags, uint32 in_Hash)
		: uUserFlags(in_Flags)
		, KeyHash(in_Hash)
	{}

	virtual ~IAkUserEventCallbackPackage() {}

	virtual void HandleAction(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo) = 0;
	virtual void CancelCallback() {};
};

class FAkFunctionPtrEventCallbackPackage : public IAkUserEventCallbackPackage
{
public:
	FAkFunctionPtrEventCallbackPackage(AkCallbackFunc CbFunc, void* Cookie, uint32 Flags, uint32 in_Hash)
		: IAkUserEventCallbackPackage(Flags, in_Hash)
		, pfnUserCallback(CbFunc)
		, pUserCookie(Cookie)
	{}

	virtual void HandleAction(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo) override;
	virtual void CancelCallback() override;

private:
	/** Copy of the user callback, for use in our own callback */
	AkCallbackFunc pfnUserCallback;

	/** Copy of the user cookie, for use in our own callback */
	void* pUserCookie;

};

class FAkBlueprintDelegateEventCallbackPackage : public IAkUserEventCallbackPackage
{
public:
	FAkBlueprintDelegateEventCallbackPackage(FOnAkPostEventCallback PostEventCallback, uint32 Flags, uint32 in_Hash)
		: IAkUserEventCallbackPackage(Flags, in_Hash)
		, BlueprintCallback(PostEventCallback)
	{}

	virtual void HandleAction(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo) override;
	virtual void CancelCallback() override;

private:
	FOnAkPostEventCallback BlueprintCallback;
};

class FAkLatentActionEventCallbackPackage : public IAkUserEventCallbackPackage
{
public:
	FAkLatentActionEventCallbackPackage(FWaitEndOfEventAction* LatentAction, uint32 in_Hash)
		: IAkUserEventCallbackPackage(AK_EndOfEvent, in_Hash)
		, EndOfEventLatentAction(LatentAction)
	{
		LatentActionValidityToken = MakeShared<FPendingLatentActionValidityToken, ESPMode::ThreadSafe>();
		EndOfEventLatentAction->ValidityToken = LatentActionValidityToken;
	}

	virtual void HandleAction(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo) override;

private:
	TSharedPtr<FPendingLatentActionValidityToken, ESPMode::ThreadSafe> LatentActionValidityToken;
	FWaitEndOfEventAction* EndOfEventLatentAction;
};

class FAkComponentCallbackManager
{
public:
	static FAkComponentCallbackManager* GetInstance();

	static FAkComponentCallbackManager* Instance;

	/** Our own event callback */
	static void AkComponentCallback(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo);

	FAkComponentCallbackManager();
	~FAkComponentCallbackManager();

	IAkUserEventCallbackPackage* CreateCallbackPackage(AkCallbackFunc in_cbFunc, void* in_Cookie, uint32 in_Flags, AkGameObjectID in_gameObjID);
	IAkUserEventCallbackPackage* CreateCallbackPackage(FOnAkPostEventCallback BlueprintCallback, uint32 in_Flags, AkGameObjectID in_gameObjID);
	IAkUserEventCallbackPackage* CreateCallbackPackage(FWaitEndOfEventAction* LatentAction, AkGameObjectID in_gameObjID);
	void RemoveCallbackPackage(IAkUserEventCallbackPackage* in_Package, AkGameObjectID in_gameObjID);

	void CancelEventCallback(void* in_Cookie);
	void CancelEventCallback(const FOnAkPostEventCallback& in_Delegate);

	void RegisterGameObject(AkGameObjectID in_gameObjID);
	void UnregisterGameObject(AkGameObjectID in_gameObjID);

	bool HasActiveEvents(AkGameObjectID in_gameObjID);

private:
	typedef TSet<IAkUserEventCallbackPackage*> PackageSet;

	void RemovePackageFromSet(PackageSet* in_pPackageSet, IAkUserEventCallbackPackage* in_pPackage, AkGameObjectID in_gameObjID);

	FCriticalSection CriticalSection;

	typedef AkGameObjectIdKeyFuncs<PackageSet, false> PackageSetGameObjectIDKeyFuncs;
	TMap<AkGameObjectID, PackageSet, FDefaultSetAllocator, PackageSetGameObjectIDKeyFuncs> GameObjectToPackagesMap;

	// Used for quick lookup in cancel
	uint32 inline GetKeyHash(void* Key);
	uint32 inline GetKeyHash(const FOnAkPostEventCallback& Key);

	void CancelKeyHash(uint32 HashToCancel);
	TMultiMap<uint32, IAkUserEventCallbackPackage*> UserCookieHashToPackageMap;
};
