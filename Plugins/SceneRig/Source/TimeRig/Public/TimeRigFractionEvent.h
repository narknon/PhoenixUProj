#pragma once
#include "CoreMinimal.h"
#include "TimeRigEvent.h"
#include "TimeRigEventReference.h"
#include "TimeRigFractionEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigFractionEvent : public UTimeRigEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference StartReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference FinishReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Fraction;
    
    UTimeRigFractionEvent();
};

