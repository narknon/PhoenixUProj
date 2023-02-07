#pragma once
#include "CoreMinimal.h"
#include "ETargetID.h"
#include "TargetTypeLocation.h"
#include "TargetTypeClosestPointOnCollision.generated.h"

class AActor;
class UTargetTracker;
class UTargetTypeBase;

UCLASS(Blueprintable)
class UTargetTypeClosestPointOnCollision : public UTargetTypeLocation {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> TargetActor;
    
public:
    UTargetTypeClosestPointOnCollision();
    UFUNCTION(BlueprintCallable)
    static UTargetTypeBase* AddTarget_ClosestPointOnCollision(UTargetTracker* TargetTracker, TEnumAsByte<ETargetID::Type> InTargetID, AActor* InTargetActor);
    
};

