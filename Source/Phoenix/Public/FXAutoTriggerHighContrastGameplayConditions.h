#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LerpVolumesLevelName.h"
#include "FXAutoTriggerHighContrastGameplayConditions.generated.h"

class UFXAutoTriggerBool;

UCLASS(Blueprintable)
class UFXAutoTriggerHighContrastGameplayConditions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerBool*> AndConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLerpVolumesLevelName> ExcludeLevels;
    
    UFXAutoTriggerHighContrastGameplayConditions();
};

