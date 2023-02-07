#pragma once
#include "CoreMinimal.h"
#include "ETargetID.h"
#include "TargetTypeActor.h"
#include "TargetTypeAccio.generated.h"

class AActor;
class UTargetTracker;
class UTargetTypeBase;

UCLASS(Blueprintable)
class UTargetTypeAccio : public UTargetTypeActor {
    GENERATED_BODY()
public:
    UTargetTypeAccio();
    UFUNCTION(BlueprintCallable)
    static UTargetTypeBase* AddTarget_Accio(UTargetTracker* TargetTracker, AActor* InTargetActor, TEnumAsByte<ETargetID::Type> InTargetID);
    
};

