#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerPrerequisiteBase.h"
#include "LerpVolumesLevelName.h"
#include "FXAutoTriggerPrerequisiteNotInLevels.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerPrerequisiteNotInLevels : public UFXAutoTriggerPrerequisiteBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLerpVolumesLevelName> Levels;
    
    UFXAutoTriggerPrerequisiteNotInLevels();
};

