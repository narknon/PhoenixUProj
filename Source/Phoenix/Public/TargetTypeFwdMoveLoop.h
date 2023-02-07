#pragma once
#include "CoreMinimal.h"
#include "ETargetID.h"
#include "TargetTypeBase.h"
#include "TargetTypeFwdMoveLoop.generated.h"

class UTargetTracker;

UCLASS(Blueprintable)
class UTargetTypeFwdMoveLoop : public UTargetTypeBase {
    GENERATED_BODY()
public:
    UTargetTypeFwdMoveLoop();
    UFUNCTION(BlueprintCallable)
    static UTargetTypeBase* AddTarget_FwdMoveLoop(UTargetTracker* TargetTracker, TEnumAsByte<ETargetID::Type> InTargetID);
    
};

