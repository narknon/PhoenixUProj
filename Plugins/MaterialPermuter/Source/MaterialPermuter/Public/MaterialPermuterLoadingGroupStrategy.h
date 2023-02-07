#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterGroupProperty.h"
#include "MaterialPermuterLoadingStrategy.h"
#include "MaterialPermuterLoadingGroupStrategy.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterLoadingGroupStrategy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterGroupProperty Group;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterLoadingStrategy Strategy;
    
    MATERIALPERMUTER_API FMaterialPermuterLoadingGroupStrategy();
};

