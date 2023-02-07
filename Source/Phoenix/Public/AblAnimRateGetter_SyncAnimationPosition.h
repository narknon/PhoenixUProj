#pragma once
#include "CoreMinimal.h"
#include "AblAnimRateGetter.h"
#include "Curves/CurveFloat.h"
#include "Templates/SubclassOf.h"
#include "AblAnimRateGetter_SyncAnimationPosition.generated.h"

class UAblAbility;

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimRateGetter_SyncAnimationPosition : public UAblAnimRateGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve DeltaToPlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumPlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumPlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> RequiredAbility;
    
public:
    UAblAnimRateGetter_SyncAnimationPosition();
};

