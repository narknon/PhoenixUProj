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

#include "AssetTypeActions_Base.h"

#include "AkAcousticTexture.h"
#include "AkAudioBank.h"
#include "AkAudioEvent.h"
#include "AkAuxBus.h"
#include "AkMediaAsset.h"
#include "AkTrigger.h"
#include "AkRtpc.h"
#include "AkInitBank.h"

template<typename AkAssetType>
class FAkAssetTypeActions_Base : public FAssetTypeActions_Base
{
public:
	FAkAssetTypeActions_Base(EAssetTypeCategories::Type InAssetCategory) : MyAssetCategory(InAssetCategory) {}

	// IAssetTypeActions Implementation
	virtual UClass* GetSupportedClass() const override { return AkAssetType::StaticClass(); }
	virtual uint32 GetCategories() override { return MyAssetCategory; }
	virtual bool ShouldForceWorldCentric() override { return true; }

private:
	EAssetTypeCategories::Type MyAssetCategory;
};


template<typename AkAssetType>
class FAkAssetTypeActions_ClearableBase : public FAkAssetTypeActions_Base<AkAssetType>
{
public:
	FAkAssetTypeActions_ClearableBase(EAssetTypeCategories::Type InAssetCategory) : FAkAssetTypeActions_Base<AkAssetType>(InAssetCategory) {}

	virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return true; }
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;

	void ClearData(TArray<TWeakObjectPtr<UAkAssetBase>> InObjects);
	void ClearDataAndDelete(TArray<TWeakObjectPtr<UAkAssetBase>> InObjects);

	bool CanDelete(const TArray<TWeakObjectPtr<UAkAssetBase>>& InObjects);

};


class FAssetTypeActions_AkAcousticTexture : public FAkAssetTypeActions_Base<UAkAcousticTexture>
{
public:
	FAssetTypeActions_AkAcousticTexture(EAssetTypeCategories::Type InAssetCategory) : FAkAssetTypeActions_Base(InAssetCategory) {}

	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AkAssetTypeActions", "AssetTypeActions_AkAcousticTexture", "Audiokinetic Texture"); }
	virtual FColor GetTypeColor() const override { return FColor(1, 185, 251); }
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
};


class FAssetTypeActions_AkAudioBank : public FAkAssetTypeActions_ClearableBase<UAkAudioBank>
{
public:
	FAssetTypeActions_AkAudioBank(EAssetTypeCategories::Type InAssetCategory) : FAkAssetTypeActions_ClearableBase(InAssetCategory) {}

	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AkAssetTypeActions", "AssetTypeActions_AkAudioBank", "Audiokinetic Bank"); }
	virtual FColor GetTypeColor() const override { return FColor(0, 192, 128); }
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return true; }
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
#if UE_4_24_OR_LATER
	virtual bool AssetsActivatedOverride(const TArray<UObject*>& InObjects, EAssetTypeActivationMethod::Type ActivationType) override;
#else
	virtual void AssetsActivated(const TArray<UObject*>& InObjects, EAssetTypeActivationMethod::Type ActivationType);
#endif

private:
	void CreateGenerateSoundDataWindow(TArray<TWeakObjectPtr<UAkAudioBank>> Objects);
	void RefreshAllBanks(TArray<TWeakObjectPtr<UAkAudioBank>> Objects);
};


class FAssetTypeActions_AkInitBank : public FAkAssetTypeActions_ClearableBase<UAkInitBank>
{
public:
	FAssetTypeActions_AkInitBank(EAssetTypeCategories::Type InAssetCategory) : FAkAssetTypeActions_ClearableBase(InAssetCategory) {}

	virtual FText GetName() const override { return NSLOCTEXT("AkAssetTypeActions", "FAssetTypeActions_AkInitBank", "Audiokinetic Init Bank"); }
	virtual FColor GetTypeColor() const override { return FColor(0, 192, 128); }
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return true; }
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;
};

class FAssetTypeActions_AkGroupValue: public FAkAssetTypeActions_ClearableBase<UAkGroupValue>
{
public:
	FAssetTypeActions_AkGroupValue(EAssetTypeCategories::Type InAssetCategory) : FAkAssetTypeActions_ClearableBase(InAssetCategory) {}

	virtual FText GetName() const override { return NSLOCTEXT("AkAssetTypeActions", "FAssetTypeActions_AkGroupValue", "Audiokinetic Group Value"); }
	virtual FColor GetTypeColor() const override { return FColor(128, 128, 128); }
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return true; }
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;
};


class FAssetTypeActions_AkAudioEvent : public FAkAssetTypeActions_ClearableBase<UAkAudioEvent>
{
public:
	FAssetTypeActions_AkAudioEvent(EAssetTypeCategories::Type InAssetCategory) : FAkAssetTypeActions_ClearableBase(InAssetCategory) {}

	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AkAssetTypeActions", "AssetTypeActions_AkAudioEvent", "Audiokinetic Event"); }
	virtual FColor GetTypeColor() const override { return FColor(0, 128, 192); }
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return true; }
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
#if UE_4_24_OR_LATER
	virtual bool AssetsActivatedOverride(const TArray<UObject*>& InObjects, EAssetTypeActivationMethod::Type ActivationType) override;
#else
	virtual void AssetsActivated(const TArray<UObject*>& InObjects, EAssetTypeActivationMethod::Type ActivationType);
#endif

private:
	void PlayEvent(TArray<TWeakObjectPtr<UAkAudioEvent>> Objects);
	void StopEvent(TArray<TWeakObjectPtr<UAkAudioEvent>> Objects);
	void GroupIntoSoundBank(TArray<TWeakObjectPtr<UAkAudioEvent>> Objects);
}; 

class FAssetTypeActions_AkAuxBus : public FAkAssetTypeActions_ClearableBase<UAkAuxBus>
{
public:
	FAssetTypeActions_AkAuxBus(EAssetTypeCategories::Type InAssetCategory) : FAkAssetTypeActions_ClearableBase(InAssetCategory) {}

	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AkAssetTypeActions", "AssetTypeActions_AkAuxBus", "Audiokinetic Auxiliary Bus"); }
	virtual FColor GetTypeColor() const override { return FColor(192, 128, 0); }
	virtual bool HasActions ( const TArray<UObject*>& InObjects ) const override { return true; }
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;
	virtual void OpenAssetEditor( const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>() ) override;

private:
	void GroupIntoSoundBank(TArray<TWeakObjectPtr<UAkAuxBus>> Objects);
};

class FAssetTypeActions_AkMediaAsset : public FAkAssetTypeActions_Base<UAkMediaAsset>
{
public:
	FAssetTypeActions_AkMediaAsset(EAssetTypeCategories::Type InAssetCategory) : FAkAssetTypeActions_Base(InAssetCategory) {}

	virtual FText GetName() const override { return NSLOCTEXT("AkAssetTypeActions", "AssetTypeActions_AkMediaAsset", "Audiokinetic Media Asset"); }
	virtual FColor GetTypeColor() const override { return FColor(128, 150, 128); }
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override;
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return true; }
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;

	void ClearData(TArray<TWeakObjectPtr<UAkMediaAsset>> InObjects);
};

class FAssetTypeActions_AkRtpc : public FAkAssetTypeActions_Base<UAkRtpc>
{
public:
	FAssetTypeActions_AkRtpc(EAssetTypeCategories::Type InAssetCategory) : FAkAssetTypeActions_Base(InAssetCategory) {}

	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AkAssetTypeActions", "AssetTypeActions_AkRtpc", "Audiokinetic Game Parameter"); }
	virtual FColor GetTypeColor() const override { return FColor(192, 128, 128); }
};

class FAssetTypeActions_AkTrigger : public FAkAssetTypeActions_Base<UAkTrigger>
{
public:
	FAssetTypeActions_AkTrigger(EAssetTypeCategories::Type InAssetCategory) : FAkAssetTypeActions_Base(InAssetCategory) {}

	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AkAssetTypeActions", "AssetTypeActions_AkTrigger", "Audiokinetic Trigger"); }
	virtual FColor GetTypeColor() const override { return FColor(128, 192, 128); }
};

