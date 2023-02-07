#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "AIPerformTaskMoveToLocation_DEBUG.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskMoveToLocation_DEBUG : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MovementSpeed;
    
    UAIPerformTaskMoveToLocation_DEBUG();
};

