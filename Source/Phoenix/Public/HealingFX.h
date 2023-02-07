#pragma once
#include "CoreMinimal.h"
#include "HealingFX.generated.h"

class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FHealingFX {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealingThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX2;
    
    PHOENIX_API FHealingFX();
};

