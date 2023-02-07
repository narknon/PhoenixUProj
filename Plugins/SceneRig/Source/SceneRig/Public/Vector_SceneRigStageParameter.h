#pragma once
#include "CoreMinimal.h"
#include "VectorProvider.h"
#include "SceneRigStage_VectorReference.h"
#include "Vector_SceneRigStageParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UVector_SceneRigStageParameter : public UVectorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_VectorReference Reference;
    
    UVector_SceneRigStageParameter();
};

