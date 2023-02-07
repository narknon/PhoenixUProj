#pragma once
#include "CoreMinimal.h"
#include "EOverlapEffectsHandlerConditionLogic.h"
#include "OverlapEffectsHandlerConditions.generated.h"

class UFXAutoTriggerBool;

USTRUCT(BlueprintType)
struct FOverlapEffectsHandlerConditions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerBool* InstigatorCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerBool* VictimCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOverlapEffectsHandlerConditionLogic Logic;
    
    FXUTIL_API FOverlapEffectsHandlerConditions();
};

