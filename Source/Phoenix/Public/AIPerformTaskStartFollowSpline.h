#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "AIPerformTaskStartFollowSpline.generated.h"

class ASplineFollowerForAI;

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskStartFollowSpline : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASplineFollowerForAI* FollowSplineForAI;
    
    UAIPerformTaskStartFollowSpline();
};

