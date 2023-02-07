#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TimeRigEvent.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class TIMERIG_API UTimeRigEvent : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CoordinateIndex;
    
    UTimeRigEvent();
};

