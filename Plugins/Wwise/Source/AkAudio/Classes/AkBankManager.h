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

/*=============================================================================
	AkAudioDevice.h: Audiokinetic audio interface object.
=============================================================================*/
#pragma once

/*------------------------------------------------------------------------------------
	AkAudioDevice system headers
------------------------------------------------------------------------------------*/


#include "AkInclude.h"
#include "AkGameplayTypes.h"
#include "Engine/EngineBaseTypes.h"
#include "CoreUObject/Public/UObject/StrongObjectPtr.h"

class UAkAudioBank;

/*------------------------------------------------------------------------------------
	Audiokinetic SoundBank Manager.
------------------------------------------------------------------------------------*/
class IAkBankCallbackInfo
{
public:
	UAkAudioBank* Bank = nullptr;

	IAkBankCallbackInfo(UAkAudioBank* bank)
	: Bank(bank)
	{}

	virtual ~IAkBankCallbackInfo() {}

	virtual void HandleAction(AkUInt32 BankID, const void * InMemoryBankPtr, AKRESULT ActionResult) = 0;
};

class FAkBankFunctionPtrCallbackInfo : public IAkBankCallbackInfo
{
public:
	FAkBankFunctionPtrCallbackInfo(AkBankCallbackFunc cbFunc, UAkAudioBank * bank, void* cookie)
		: IAkBankCallbackInfo(bank)
		, CallbackFunc(cbFunc)
		, UserCookie(cookie)
	{}

	virtual void HandleAction(AkUInt32 BankID, const void * InMemoryBankPtr, AKRESULT ActionResult) override;

private:
	AkBankCallbackFunc CallbackFunc;
	void* UserCookie;
};

class FAkBankLatentActionCallbackInfo : public IAkBankCallbackInfo
{
public:
	FAkBankLatentActionCallbackInfo(UAkAudioBank* bank, FWaitEndBankAction* LatentAction)
		: IAkBankCallbackInfo(bank)
		, BankLatentAction(LatentAction)
	{
		LatentActionValidityToken = MakeShared<FPendingLatentActionValidityToken, ESPMode::ThreadSafe>();
		BankLatentAction->ValidityToken = LatentActionValidityToken;
	}

	virtual void HandleAction(AkUInt32 BankID, const void * InMemoryBankPtr, AKRESULT ActionResult) override;

private:
	TSharedPtr<FPendingLatentActionValidityToken, ESPMode::ThreadSafe> LatentActionValidityToken;
	FWaitEndBankAction* BankLatentAction;
};

class FAkBankBlueprintDelegateCallbackInfo : public IAkBankCallbackInfo
{
public:
	FAkBankBlueprintDelegateCallbackInfo(UAkAudioBank * bank, const FOnAkBankCallback& BlueprintCallback)
		: IAkBankCallbackInfo(bank)
		, BankBlueprintCallback(BlueprintCallback)
	{}

	virtual void HandleAction(AkUInt32 BankID, const void * InMemoryBankPtr, AKRESULT ActionResult) override;

private:
	FOnAkBankCallback BankBlueprintCallback;
};

class AKAUDIO_API FAkBankManager
{
public:
	FAkBankManager();
	~FAkBankManager();

	static FAkBankManager* GetInstance();

	static void BankLoadCallback(
		AkUInt32		in_bankID,
		const void *	in_pInMemoryBankPtr,
		AKRESULT		in_eLoadResult,
		void *			in_pCookie
	);

	static void BankUnloadCallback(
		AkUInt32		in_bankID,
		const void *	in_pInMemoryBankPtr,
		AKRESULT		in_eUnloadResult,
		void *			in_pCookie
	);

	void AddLoadedBank(UAkAudioBank* Bank);

	void RemoveLoadedBank(UAkAudioBank* Bank);

	void ClearLoadedBanks();

	const TSet<UAkAudioBank*> GetLoadedBankList() const
	{
		FScopeLock AutoLock(&BankLock);
		TSet<UAkAudioBank*> Banks;
		for (const TWeakObjectPtr<UAkAudioBank>& Bank : LoadedBanks)
		{
			if (Bank.IsValid())
			{
				Banks.Add(Bank.Get());
			}
		}
		return Banks;
	}

private:
	void AddBankInternal(TWeakObjectPtr<UAkAudioBank> Bank);
	void RemoveBankInternal(TWeakObjectPtr<UAkAudioBank> Bank);

private:
	static FAkBankManager* Instance;
	TSet<TWeakObjectPtr<UAkAudioBank>> LoadedBanks;
	mutable FCriticalSection BankLock;
};