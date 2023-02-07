#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "SceneRigStage_TransformReference.h"
#include "Transform_SceneRigStageParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UTransform_SceneRigStageParameter : public UTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_TransformReference Reference;
    
    UTransform_SceneRigStageParameter();
};

