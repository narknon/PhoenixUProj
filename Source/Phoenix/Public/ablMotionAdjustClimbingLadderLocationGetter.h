#pragma once
#include "CoreMinimal.h"
#include "EClimbingLadderState.h"
#include "ablMotionAdjustTargetLocationGetter.h"
#include "ablMotionAdjustClimbingLadderLocationGetter.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablMotionAdjustClimbingLadderLocationGetter : public UablMotionAdjustTargetLocationGetter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EClimbingLadderState::Type> ClimbingLadderState;
    
    UablMotionAdjustClimbingLadderLocationGetter();
};

