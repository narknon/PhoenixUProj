#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "EEnemyAIAction.h"
#include "EEnemyAIActionDoneReason.h"
#include "AIPerformTaskRotateTo.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskRotateTo : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Yaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRelative;
    
    UAIPerformTaskRotateTo();
private:
    UFUNCTION(BlueprintCallable)
    void RotateToComplete(EEnemyAIAction InAction, EEnemyAIActionDoneReason InReason);
    
};

