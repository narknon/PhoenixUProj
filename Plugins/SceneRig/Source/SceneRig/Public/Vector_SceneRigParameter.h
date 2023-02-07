#pragma once
#include "CoreMinimal.h"
#include "VectorProvider.h"
#include "SceneRigParameterBinding_Vector.h"
#include "Vector_SceneRigParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UVector_SceneRigParameter : public UVectorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_Vector BoundParameter;
    
    UVector_SceneRigParameter();
};

