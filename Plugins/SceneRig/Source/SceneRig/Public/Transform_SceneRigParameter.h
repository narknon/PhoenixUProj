#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "SceneRigParameterBinding_Transform.h"
#include "Transform_SceneRigParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UTransform_SceneRigParameter : public UTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_Transform BoundParameter;
    
    UTransform_SceneRigParameter();
};

