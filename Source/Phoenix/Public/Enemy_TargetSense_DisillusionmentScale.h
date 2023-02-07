#pragma once
#include "CoreMinimal.h"
#include "Enemy_TargetSense_DisillusionmentScale.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_TargetSense_DisillusionmentScale {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoreEffectiveScale;
    
    PHOENIX_API FEnemy_TargetSense_DisillusionmentScale();
};

