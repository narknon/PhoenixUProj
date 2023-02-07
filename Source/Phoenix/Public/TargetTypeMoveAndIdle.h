#pragma once
#include "CoreMinimal.h"
#include "ETargetID.h"
#include "TargetTypeBase.h"
#include "TargetTypeMoveAndIdle.generated.h"

class UTargetTracker;

UCLASS(Blueprintable)
class UTargetTypeMoveAndIdle : public UTargetTypeBase {
    GENERATED_BODY()
public:
    UTargetTypeMoveAndIdle();
    UFUNCTION(BlueprintCallable)
    static UTargetTypeBase* AddTarget_MoveAndIdle(UTargetTracker* TargetTracker, TEnumAsByte<ETargetID::Type> InTargetID);
    
};

