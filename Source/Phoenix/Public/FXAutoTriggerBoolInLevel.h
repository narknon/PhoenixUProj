#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "LerpVolumesLevelName.h"
#include "FXAutoTriggerBoolInLevel.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolInLevel : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesLevelName Level;
    
    UFXAutoTriggerBoolInLevel();
};

