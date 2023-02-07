#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "Templates/SubclassOf.h"
#include "AIPerformTaskJumpDown.generated.h"

class UAblAbility;

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskJumpDown : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> JumpDownAbility;
    
    UAIPerformTaskJumpDown();
private:
    UFUNCTION(BlueprintCallable)
    void JumpFinished();
    
};

