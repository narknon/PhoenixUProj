#pragma once
#include "CoreMinimal.h"
#include "TimeRigEvent.h"
#include "TimeRigEventReference.h"
#include "TimeRigLastOfEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigLastOfEvent : public UTimeRigEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTimeRigEventReference> InputEventReferences;
    
    UTimeRigLastOfEvent();
};

