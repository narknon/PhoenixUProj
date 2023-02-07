#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EMountFlyingGait.h"
#include "ESpeedType.h"
#include "AblBranchConditionMountFlyingSpeed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionMountFlyingSpeed : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EMountFlyingGait> FlyingGaits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESpeedType::Type> SpeedType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BufferSampleTime;
    
public:
    UAblBranchConditionMountFlyingSpeed();
};

