#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterInstanceHandCraftedUIPair.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FMaterialPermuterInstanceHandCraftedUIPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> MaterialInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> HandCrafted;
    
    MATERIALPERMUTER_API FMaterialPermuterInstanceHandCraftedUIPair();
};

