#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "FXAutoTriggerBoolGameplayHighContrast.generated.h"

class UFXAutoTriggerHighContrastGameplayConditions;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolGameplayHighContrast : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerHighContrastGameplayConditions* Conditions;
    
    UFXAutoTriggerBoolGameplayHighContrast();
};

