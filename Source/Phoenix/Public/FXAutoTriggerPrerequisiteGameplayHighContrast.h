#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerPrerequisiteBase.h"
#include "FXAutoTriggerPrerequisiteGameplayHighContrast.generated.h"

class UFXAutoTriggerHighContrastGameplayConditions;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerPrerequisiteGameplayHighContrast : public UFXAutoTriggerPrerequisiteBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerHighContrastGameplayConditions* Conditions;
    
    UFXAutoTriggerPrerequisiteGameplayHighContrast();
};

