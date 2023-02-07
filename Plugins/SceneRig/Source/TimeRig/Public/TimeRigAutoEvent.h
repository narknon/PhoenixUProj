#pragma once
#include "CoreMinimal.h"
#include "TimeRigCoordinate.h"
#include "TimeRigEvent.h"
#include "TimeRigSettableEvent.h"
#include "TimeRigAutoEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigAutoEvent : public UTimeRigEvent, public ITimeRigSettableEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigCoordinate DefaultOffset;
    
    UTimeRigAutoEvent();
    
    // Fix for true pure virtual functions not being implemented
};

