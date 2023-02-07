#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "EPerformTaskFinishAction.h"
#include "SceneAction_PerformTaskFollowSpline.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_PerformTaskFollowSpline : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* SplineFollowerActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTaskFinishAction FinishAction;
    
    USceneAction_PerformTaskFollowSpline();
};

