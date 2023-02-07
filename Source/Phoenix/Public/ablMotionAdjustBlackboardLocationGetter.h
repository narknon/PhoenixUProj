#pragma once
#include "CoreMinimal.h"
#include "ablMotionAdjustTargetLocationGetter.h"
#include "ablMotionAdjustBlackboardLocationGetter.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablMotionAdjustBlackboardLocationGetter : public UablMotionAdjustTargetLocationGetter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BlackboardKeyName;
    
    UablMotionAdjustBlackboardLocationGetter();
};

