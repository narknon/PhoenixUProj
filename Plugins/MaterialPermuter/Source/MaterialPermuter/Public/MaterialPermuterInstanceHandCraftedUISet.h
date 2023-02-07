#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterInstanceHandCraftedUIPair.h"
#include "MaterialPermuterKeyProperty.h"
#include "MaterialPermuterInstanceHandCraftedUISet.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterInstanceHandCraftedUISet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterKeyProperty Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialPermuterInstanceHandCraftedUIPair> Pairs;
    
    MATERIALPERMUTER_API FMaterialPermuterInstanceHandCraftedUISet();
};

