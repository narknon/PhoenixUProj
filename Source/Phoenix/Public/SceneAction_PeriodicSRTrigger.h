#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_PeriodicSRTrigger.generated.h"

class USceneRig;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_PeriodicSRTrigger : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinTriggerTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxTriggerTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<USceneRig*, float> WeightedPeriodicSceneRigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTriggerImmediately;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopScenerigsAtEnd;
    
    USceneAction_PeriodicSRTrigger();
};

