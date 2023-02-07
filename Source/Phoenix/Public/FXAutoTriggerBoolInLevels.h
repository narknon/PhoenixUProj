#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "LerpVolumesLevelName.h"
#include "FXAutoTriggerBoolInLevels.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolInLevels : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLerpVolumesLevelName> Levels;
    
    UFXAutoTriggerBoolInLevels();
};

