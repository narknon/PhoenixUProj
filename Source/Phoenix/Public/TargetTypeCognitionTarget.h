#pragma once
#include "CoreMinimal.h"
#include "ETargetID.h"
#include "TargetTypeLocation.h"
#include "TargetTypeCognitionTarget.generated.h"

class AActor;
class UTargetTracker;
class UTargetTypeBase;

UCLASS(Blueprintable)
class UTargetTypeCognitionTarget : public UTargetTypeLocation {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* Sense;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> TargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLookAt;
    
public:
    UTargetTypeCognitionTarget();
    UFUNCTION(BlueprintCallable)
    static UTargetTypeBase* AddTarget_CognitionTarget(UTargetTracker* TargetTracker, TEnumAsByte<ETargetID::Type> InTargetID, AActor* InTargetActor, UClass* InSense, bool NewBLookAt);
    
};

