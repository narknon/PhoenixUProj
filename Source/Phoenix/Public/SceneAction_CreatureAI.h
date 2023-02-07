#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "ECreatureIdleOverrideState.h"
#include "ECreatureStance.h"
#include "ESceneAction_CreatureFlyingOption.h"
#include "SceneAction_CreatureAI.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_CreatureAI : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSet_IdleOverrideState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureIdleOverrideState IdleOverrideState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSet_StationaryForNurtureInteract;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStationaryForNurtureInteract;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSet_FlyingOption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneAction_CreatureFlyingOption FlyingOption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSet_EnablePerception;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnablePerception;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSet_DesiredStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureStance DesiredStance;
    
    USceneAction_CreatureAI();
};

