#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterInstanceHandCraftedList.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FMaterialPermuterInstanceHandCraftedList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMaterialInterface>> Materials;
    
    MATERIALPERMUTER_API FMaterialPermuterInstanceHandCraftedList();
};

