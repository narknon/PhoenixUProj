#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "Chaos/ChaosEngineInterface.h"
#include "AblBranchConditionSlopeSlideDone.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionSlopeSlideDone : public UAblTaskCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Timer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EPhysicalSurface> SurfaceType;
    
    UAblBranchConditionSlopeSlideDone();
};

