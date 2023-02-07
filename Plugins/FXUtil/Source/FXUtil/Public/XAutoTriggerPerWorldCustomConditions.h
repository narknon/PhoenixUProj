#pragma once
#include "CoreMinimal.h"
#include "XAutoTriggerCustomConditionsSet.h"
#include "XAutoTriggerPerWorldCustomConditions.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FXUTIL_API FXAutoTriggerPerWorldCustomConditions {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FXAutoTriggerCustomConditionsSet> Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FXAutoTriggerCustomConditionsSet WorldConditions;
    
    FXAutoTriggerPerWorldCustomConditions();
};

