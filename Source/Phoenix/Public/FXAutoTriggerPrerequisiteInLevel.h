#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerPrerequisiteBase.h"
#include "LerpVolumesLevelName.h"
#include "FXAutoTriggerPrerequisiteInLevel.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerPrerequisiteInLevel : public UFXAutoTriggerPrerequisiteBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesLevelName Level;
    
    UFXAutoTriggerPrerequisiteInLevel();
};

