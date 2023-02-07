#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerPrerequisiteBase.h"
#include "LerpVolumesLevelName.h"
#include "FXAutoTriggerPrerequisiteInLevels.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerPrerequisiteInLevels : public UFXAutoTriggerPrerequisiteBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLerpVolumesLevelName> Levels;
    
    UFXAutoTriggerPrerequisiteInLevels();
};

