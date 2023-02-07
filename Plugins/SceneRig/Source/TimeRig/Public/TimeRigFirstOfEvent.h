#pragma once
#include "CoreMinimal.h"
#include "TimeRigEvent.h"
#include "TimeRigEventReference.h"
#include "TimeRigFirstOfEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigFirstOfEvent : public UTimeRigEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTimeRigEventReference> InputEventReferences;
    
    UTimeRigFirstOfEvent();
};

