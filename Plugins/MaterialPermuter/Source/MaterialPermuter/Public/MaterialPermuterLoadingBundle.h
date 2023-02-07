#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "EMaterialPermuterLoadingBundleState.h"
#include "EMaterialPermuterLoadingPriority.h"
#include "MasterMaterialAssetSet.h"
#include "MaterialPermuterKey.h"
#include "MaterialPermuterLoadingBundleLoadedDynamicDelegateDelegate.h"
#include "MaterialPermuterLoadingBundlePercentageDynamicDelegateDelegate.h"
#include "MaterialPermuterLoadingBundle.generated.h"

class AActor;
class UMaterialInterface;
class UMaterialPermuterLoadingBundle;
class UObject;

UCLASS(Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UMaterialPermuterLoadingBundle : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSoftObjectPtr<UMaterialInterface>> Assets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> LoadedAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMaterialInterface>> MissingAssets;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterLoadingBundleLoadedDynamicDelegate OnBundleLoadedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterLoadingBundlePercentageDynamicDelegate OnBundlePercentLoadedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadingPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadingBundleState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimespan StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TimeWarnings;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastPercentageBroadcast;
    
public:
    UMaterialPermuterLoadingBundle();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void ValidBundle(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static AActor* GetWorldBundleOwner(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetPercentageLoaded(float& Loaded) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void FullyLoaded(bool& bIsFullyLoaded) const;
    
    UFUNCTION(BlueprintCallable)
    static UMaterialPermuterLoadingBundle* CreateMaterialSetBundleForOwnerOnly(AActor* Owner, EMaterialPermuterLoadingPriority NewPriority, bool bAttachedChildren, bool bComponentChildren);
    
    UFUNCTION(BlueprintCallable)
    static UMaterialPermuterLoadingBundle* CreateMaterialSetBundle(AActor* Owner, const FMasterMaterialAssetSet& MaterialAssetSet, EMaterialPermuterLoadingPriority NewPriority);
    
    UFUNCTION(BlueprintCallable)
    static UMaterialPermuterLoadingBundle* CreateKeysMaterialSetBundle(AActor* Owner, TArray<FMaterialPermuterKey> Keys, const FMasterMaterialAssetSet& MaterialAssetSet, EMaterialPermuterLoadingPriority NewPriority);
    
    UFUNCTION(BlueprintCallable)
    static UMaterialPermuterLoadingBundle* CreateKeysBundleForOwnerOnly(AActor* Owner, TArray<FMaterialPermuterKey> Keys, EMaterialPermuterLoadingPriority NewPriority, bool bAttachedChildren, bool bComponentChildren);
    
    UFUNCTION(BlueprintCallable)
    static UMaterialPermuterLoadingBundle* CreateKeysBundle(AActor* Owner, TArray<FMaterialPermuterKey> Keys, EMaterialPermuterLoadingPriority NewPriority);
    
    UFUNCTION(BlueprintCallable)
    static UMaterialPermuterLoadingBundle* CreateKeyMaterialSetBundle(AActor* Owner, FMaterialPermuterKey Key, const FMasterMaterialAssetSet& MaterialAssetSet, EMaterialPermuterLoadingPriority NewPriority);
    
    UFUNCTION(BlueprintCallable)
    static UMaterialPermuterLoadingBundle* CreateKeyBundleForOwnerOnly(AActor* Owner, FMaterialPermuterKey Key, EMaterialPermuterLoadingPriority NewPriority, bool bAttachedChildren, bool bComponentChildren);
    
    UFUNCTION(BlueprintCallable)
    static UMaterialPermuterLoadingBundle* CreateKeyBundle(AActor* Owner, FMaterialPermuterKey Key, EMaterialPermuterLoadingPriority NewPriority);
    
};

