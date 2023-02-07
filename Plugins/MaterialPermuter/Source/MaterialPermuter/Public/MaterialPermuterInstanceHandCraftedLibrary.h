#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MaterialPermuterInstanceHandCraftedKeySet.h"
#include "MaterialPermuterInstanceHandCraftedKeySetList.h"
#include "MaterialPermuterInstanceHandCraftedLibrary.generated.h"

class UMaterial;
class UMaterialInterface;

UCLASS(Blueprintable)
class MATERIALPERMUTER_API UMaterialPermuterInstanceHandCraftedLibrary : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<UMaterialInterface>, FMaterialPermuterInstanceHandCraftedKeySet> HandCraftedMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<UMaterial>, FMaterialPermuterInstanceHandCraftedKeySetList> HandCraftedMasterMap;
    
    UMaterialPermuterInstanceHandCraftedLibrary();
    UFUNCTION(BlueprintCallable)
    void Build();
    
};

