#pragma once
#include "CoreMinimal.h"
#include "FloatProvider.h"
#include "SceneRigParameterBinding_Float.h"
#include "Float_SceneRigParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UFloat_SceneRigParameter : public UFloatProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_Float BoundParameter;
    
    UFloat_SceneRigParameter();
};

