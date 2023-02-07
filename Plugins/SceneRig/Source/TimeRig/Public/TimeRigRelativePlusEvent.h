#pragma once
#include "CoreMinimal.h"
#include "TimeRigEvent.h"
#include "TimeRigEventReference.h"
#include "TimeRigRelativePlusEvent.generated.h"

class UFloatProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigRelativePlusEvent : public UTimeRigEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference ParentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* OffsetProvider;
    
    UTimeRigRelativePlusEvent();
};

