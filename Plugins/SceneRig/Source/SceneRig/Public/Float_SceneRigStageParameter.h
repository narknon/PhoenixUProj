#pragma once
#include "CoreMinimal.h"
#include "FloatProvider.h"
#include "SceneRigStage_FloatReference.h"
#include "Float_SceneRigStageParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UFloat_SceneRigStageParameter : public UFloatProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_FloatReference Reference;
    
    UFloat_SceneRigStageParameter();
};

