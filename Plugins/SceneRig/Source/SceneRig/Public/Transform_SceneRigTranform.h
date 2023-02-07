#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "Transform_SceneRigTranform.generated.h"

class USceneAction_Transform;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UTransform_SceneRigTranform : public UTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneAction_Transform* TransformAction;
    
    UTransform_SceneRigTranform();
};

