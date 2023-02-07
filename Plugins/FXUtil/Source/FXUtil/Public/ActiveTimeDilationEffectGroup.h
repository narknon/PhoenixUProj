#pragma once
#include "CoreMinimal.h"
#include "ActiveTimeDilationEffect.h"
#include "ActiveTimeDilationEffectGroup.generated.h"

USTRUCT(BlueprintType)
struct FActiveTimeDilationEffectGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FActiveTimeDilationEffect> ActiveEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CounterDilationEnabledCount;
    
    FXUTIL_API FActiveTimeDilationEffectGroup();
};

