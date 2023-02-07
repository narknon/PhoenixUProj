#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterInstanceHandCraftedList.h"
#include "MaterialPermuterInstanceHandCraftedKeySetList.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterInstanceHandCraftedKeySetList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FMaterialPermuterInstanceHandCraftedList> PerKey;
    
    MATERIALPERMUTER_API FMaterialPermuterInstanceHandCraftedKeySetList();
};

