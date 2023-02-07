#pragma once
#include "CoreMinimal.h"
#include "TimeRigCoordinate.h"
#include "TimeRigEvent.h"
#include "TimeRigSettableEvent.h"
#include "TimeRigCustomEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigCustomEvent : public UTimeRigEvent, public ITimeRigSettableEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CustomEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigCoordinate DefaultOffset;
    
    UTimeRigCustomEvent();
    
    // Fix for true pure virtual functions not being implemented
};

