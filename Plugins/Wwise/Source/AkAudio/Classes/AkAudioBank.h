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

#include "AkAssetBase.h"
#include "AkAudioBank.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class AKAUDIO_API UAkAudioBank : public UAkAssetBase
{
	GENERATED_BODY()

public:
	// Only applicable when you don't use the new Event-Based Packaging workflow
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behaviour")
	bool AutoLoad = true;

	UPROPERTY(VisibleAnywhere, Category = "AkAudioBank")
	TMap<FString, UAkAssetPlatformData*> LocalizedPlatformAssetDataMap;

	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category = "AkAudioBank")
	TSet<TSoftObjectPtr<UAkAudioEvent>> LinkedAkEvents;
private:
	UPROPERTY(Transient)
	UAkAssetPlatformData* CurrentLocalizedPlatformAssetData = nullptr;

public:
	void LoadBank() override;
	void UnloadBank() override;

	virtual bool IsLocalized() const override   { return LocalizedPlatformAssetDataMap.Num() > 0; }

	bool SwitchLanguage(const FString& newAudioCulture);

#if WITH_EDITOR
	void AddAkAudioEvent(UAkAudioEvent* event);
	void RemoveAkAudioEvent(UAkAudioEvent* event);
#endif

#if WITH_EDITOR || WITH_EDITORONLY_DATA
	void PopulateAkAudioEvents();
#endif

#if CPP
	/**
	 * Loads an AkBank.
	 *
	 * @return Returns true if the load was successful, otherwise false
	 */
	bool LegacyLoad();

	/**
	* Loads an AkBank, using the latent action to flag completion.
	*/
	bool LegacyLoad(FWaitEndBankAction* LoadBankLatentAction);

	/**
	 * Loads an AkBank asynchronously.
	 *
	 * @param in_pfnBankCallback		Function to call on completion
	 * @param in_pCookie				Cookie to pass in callback
	 * @return Returns true if the load was successful, otherwise false
	 */
	bool LegacyLoadAsync(void* in_pfnBankCallback, void* in_pCookie);

	/**
	* Loads an AkBank asynchronously, from Blueprint
	*
	* @param BankLoadedCallback		Blueprint Delegate to call on completion
	* @return Returns true if the load was successful, otherwise false
	*/
	bool LegacyLoadAsync(const FOnAkBankCallback& BankLoadedCallback);

	/**
	 * Unloads an AkBank.
	 */
	void LegacyUnload();

	/**
	* Unloads an AkBank, using the latent action to flag completion.
	*/
	void LegacyUnload(FWaitEndBankAction* LoadBankLatentAction);

	/**
	 * Unloads an AkBank asynchronously.
	 *
	 * @param in_pfnBankCallback		Function to call on completion
	 * @param in_pCookie				Cookie to pass in callback
	 */
	void LegacyUnloadAsync(void* in_pfnBankCallback, void* in_pCookie);

	/**
	* Unloads an AkBank asynchronously, from Blueprint
	*
	* @param BankUnloadedCallback		Blueprint Delegate to call on completion
	*/
	void LegacyUnloadAsync(const FOnAkBankCallback& BankUnloadedCallback);
#endif

#if WITH_EDITOR
	UAkAssetData* FindOrAddAssetData(const FString& platform, const FString& language) override;

	void Reset(TArray<FAssetData>& InOutAssetsToDelete) override;

	bool NeedsRebuild(const TSet<FString>& PlatformsToBuild, const TSet<FString>& LanguagesToBuild, const ISoundBankInfoCache* SoundBankInfoCache) const override;
#endif

	friend class AkEventBasedIntegrationBehavior;

public:
	FString LoadedBankName;
	FThreadSafeCounter LegacyLoadedRefCnt;

protected:
	UAkAssetData* CreateAssetData(UObject* parent) const override;
	UAkAssetData* GetAssetData() const override;

private:
	void PostLoad() override;
	void Serialize(FArchive& Ar) override;

	bool LoadLocalizedData(const FString& audioCulture);
	void UnloadLocalizedData();

	void AssetBaseLoadBank();
	void AssetBaseUnloadBank();

};
