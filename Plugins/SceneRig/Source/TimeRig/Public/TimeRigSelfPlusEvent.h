#pragma once
#include "CoreMinimal.h"
#include "TimeRigEvent.h"
#include "TimeRigSelfPlusEvent.generated.h"

class UFloatProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigSelfPlusEvent : public UTimeRigEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* OffsetProvider;
    
    UTimeRigSelfPlusEvent();
};

