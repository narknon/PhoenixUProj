#pragma once
#include "CoreMinimal.h"
#include "BlendSpaceInputProvider.h"
#include "SceneRigStage_FloatReference.h"
#include "BlendSpaceInput_SceneRigStageParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UBlendSpaceInput_SceneRigStageParameter : public UBlendSpaceInputProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_FloatReference Reference;
    
    UBlendSpaceInput_SceneRigStageParameter();
};

