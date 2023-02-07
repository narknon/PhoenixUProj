#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterKeyMap.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterKeyMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SubTypes;
    
    MATERIALPERMUTER_API FMaterialPermuterKeyMap();
};

