#pragma once
#include "CoreMinimal.h"
#include "ETimeRigExternalEventConstraint.h"
#include "TimeRigEvent.h"
#include "TimeRigSettableEvent.h"
#include "TimeRigExternalEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigExternalEvent : public UTimeRigEvent, public ITimeRigSettableEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeRigExternalEventConstraint Constraint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultTime;
    
    UTimeRigExternalEvent();
    
    // Fix for true pure virtual functions not being implemented
};

