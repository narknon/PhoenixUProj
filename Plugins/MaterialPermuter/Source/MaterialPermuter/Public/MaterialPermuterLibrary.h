#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MaterialPermuterCopyParameterOverrides.h"
#include "MaterialPermuterKeyCache.h"
#include "MaterialPermuterKeyMap.h"
#include "MaterialPermuterMaterialMap.h"
#include "MaterialPermuterLibrary.generated.h"

class UMaterialPermuterInstanceHandCraftedLibrary;
class UMaterialPermuterLoadingStrategiesAsset;

UCLASS(Blueprintable)
class MATERIALPERMUTER_API UMaterialPermuterLibrary : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialPermuterInstanceHandCraftedLibrary* InstanceHandCraftedLibrary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableMIDCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MIDCacheTimeoutSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FMaterialPermuterMaterialMap> Permutations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialPermuterLoadingStrategiesAsset* LoadingStrategiesAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterCopyParameterOverrides CopyParameterOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FMaterialPermuterKeyMap> ValidPermutations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialPermuterKeyCache KeyCache;
    
    UMaterialPermuterLibrary();
};

