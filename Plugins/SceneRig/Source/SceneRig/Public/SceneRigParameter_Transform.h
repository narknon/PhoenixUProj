#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameter.h"
#include "SceneRigParameter_Transform.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigParameter_Transform : public USceneRigParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* Value;
    
    USceneRigParameter_Transform();
};

