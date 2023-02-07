#pragma once
#include "CoreMinimal.h"
#include "TimeRigCoordinate.h"
#include "TimeRigEvent.h"
#include "TimeRigEventReference.h"
#include "TimeRigRelativeEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigRelativeEvent : public UTimeRigEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference ParentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigCoordinate Offset;
    
    UTimeRigRelativeEvent();
};

