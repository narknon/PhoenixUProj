#pragma once
#include "CoreMinimal.h"
#include "ETargetID.h"
#include "TargetTypeActor.h"
#include "TargetTypeAutoTargetOrDesiredDirection.generated.h"

class UTargetTracker;
class UTargetTypeBase;

UCLASS(Blueprintable)
class UTargetTypeAutoTargetOrDesiredDirection : public UTargetTypeActor {
    GENERATED_BODY()
public:
    UTargetTypeAutoTargetOrDesiredDirection();
    UFUNCTION(BlueprintCallable)
    static UTargetTypeBase* AddTarget_AutoTargetOrDesiredDirection(UTargetTracker* TargetTracker, TEnumAsByte<ETargetID::Type> InTargetID);
    
};

