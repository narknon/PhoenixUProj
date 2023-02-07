#pragma once
#include "CoreMinimal.h"
#include "AblAnimRateGetter.h"
#include "UObject/NoExportTypes.h"
#include "AblAnimRateGetter_SpeedAdjust.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimRateGetter_SpeedAdjust : public UAblAnimRateGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D AngleRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D AnimRateRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StairsJogMultiplier;
    
public:
    UAblAnimRateGetter_SpeedAdjust();
};

