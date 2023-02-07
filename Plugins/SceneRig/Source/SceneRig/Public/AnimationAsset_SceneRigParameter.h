#pragma once
#include "CoreMinimal.h"
#include "AnimationProvider.h"
#include "SceneRigParameterBinding_Animation.h"
#include "AnimationAsset_SceneRigParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UAnimationAsset_SceneRigParameter : public UAnimationProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_Animation BoundParameter;
    
    UAnimationAsset_SceneRigParameter();
};

