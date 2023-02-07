#pragma once
#include "CoreMinimal.h"
#include "ETargetID.h"
#include "TargetTypeActor.h"
#include "TargetTypeBroomSpline.generated.h"

class AActor;
class UTargetTracker;
class UTargetTypeBase;

UCLASS(Blueprintable)
class UTargetTypeBroomSpline : public UTargetTypeActor {
    GENERATED_BODY()
public:
    UTargetTypeBroomSpline();
    UFUNCTION(BlueprintCallable)
    static UTargetTypeBase* AddTarget_BroomSpline(UTargetTracker* TargetTracker, TEnumAsByte<ETargetID::Type> InTargetID, AActor* InTargetActor);
    
};

