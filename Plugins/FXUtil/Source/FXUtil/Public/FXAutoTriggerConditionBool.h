#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerCondition.h"
#include "FXAutoTriggerFXSpawnInfo.h"
#include "FXAutoTriggerConditionBool.generated.h"

class UFXAutoTriggerBool;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerConditionBool : public UFXAutoTriggerCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerBool* Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFXAutoTriggerFXSpawnInfo SpawnInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSpawnInfo;
    
    UFXAutoTriggerConditionBool();
};

