#pragma once
#include "CoreMinimal.h"
#include "AnimationProvider.h"
#include "SceneRigStage_AnimationReference.h"
#include "Animation_SceneRigStageParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UAnimation_SceneRigStageParameter : public UAnimationProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_AnimationReference Reference;
    
    UAnimation_SceneRigStageParameter();
};

