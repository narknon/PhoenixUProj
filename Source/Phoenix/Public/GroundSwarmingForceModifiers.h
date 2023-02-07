#pragma once
#include "CoreMinimal.h"
#include "GroundSwarmingForceModifier.h"
#include "GroundSwarmingForceModifiers.generated.h"

USTRUCT(BlueprintType)
struct FGroundSwarmingForceModifiers {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGroundSwarmingForceModifier> ForceModifiers;
    
    PHOENIX_API FGroundSwarmingForceModifiers();
};

