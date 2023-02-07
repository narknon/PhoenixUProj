#pragma once
#include "CoreMinimal.h"
#include "TimeRigCoordinate.h"
#include "TimeRigEvent.h"
#include "TimeRigChainEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigChainEvent : public UTimeRigEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigCoordinate Offset;
    
    UTimeRigChainEvent();
};

