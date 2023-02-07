#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "EPerformTaskFinishAction.h"
#include "SceneAction_WaitForPlayer.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_WaitForPlayer : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOrientTowardsPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTaskFinishAction FinishAction;
    
    USceneAction_WaitForPlayer();
};

