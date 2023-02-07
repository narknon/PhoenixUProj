#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MultiFX2Var.h"
#include "FXAutoTriggerFXSpawnInfo.h"
#include "FXAutoTriggerDefinitionAsset.generated.h"

class UFXAutoTriggerConditionBase;
class UFXAutoTriggerPrerequisiteBase;
class UFXAutoTriggerRequiredActorsBase;
class UFXAutoTriggerUpdateBase;

UCLASS(Blueprintable)
class FXUTIL_API UFXAutoTriggerDefinitionAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerPrerequisiteBase* Prerequisite;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerRequiredActorsBase* RequiredActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerConditionBase* TriggerCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerUpdateBase*> Updates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMultiFX2Var> FX;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFXAutoTriggerFXSpawnInfo DefaultSpawnInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SleepWhenFinishingImmediately;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SleepWhenStartFails;
    
    UFXAutoTriggerDefinitionAsset();
};

