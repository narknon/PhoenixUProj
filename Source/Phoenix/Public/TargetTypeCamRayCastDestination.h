#pragma once
#include "CoreMinimal.h"
#include "ETargetID.h"
#include "TargetTypeBase.h"
#include "TargetTypeCamRayCastDestination.generated.h"

class UTargetTracker;

UCLASS(Blueprintable)
class UTargetTypeCamRayCastDestination : public UTargetTypeBase {
    GENERATED_BODY()
public:
    UTargetTypeCamRayCastDestination();
    UFUNCTION(BlueprintCallable)
    static UTargetTypeBase* AddTarget_CamRayCastDestination(UTargetTracker* TargetTracker, TEnumAsByte<ETargetID::Type> InTargetID);
    
};

