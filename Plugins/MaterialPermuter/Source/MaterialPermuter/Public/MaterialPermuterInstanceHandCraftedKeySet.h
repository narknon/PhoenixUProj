#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterInstanceHandCraftedKeySet.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FMaterialPermuterInstanceHandCraftedKeySet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, TSoftObjectPtr<UMaterialInterface>> PerKey;
    
    MATERIALPERMUTER_API FMaterialPermuterInstanceHandCraftedKeySet();
};

