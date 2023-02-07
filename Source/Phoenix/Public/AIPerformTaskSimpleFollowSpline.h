#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "AIPerformTaskSimpleFollowSpline.generated.h"

class ASimpleSplineFollowerForAI;

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskSimpleFollowSpline : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimpleSplineFollowerForAI* FollowSimpleSplineForAI;
    
    UAIPerformTaskSimpleFollowSpline();
};

