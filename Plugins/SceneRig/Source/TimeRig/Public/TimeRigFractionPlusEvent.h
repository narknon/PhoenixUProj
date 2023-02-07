#pragma once
#include "CoreMinimal.h"
#include "TimeRigEvent.h"
#include "TimeRigEventReference.h"
#include "TimeRigFractionPlusEvent.generated.h"

class UFloatProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigFractionPlusEvent : public UTimeRigEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference StartReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference FinishReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* FractionProvider;
    
    UTimeRigFractionPlusEvent();
};

