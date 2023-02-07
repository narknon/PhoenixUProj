#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_Animation.h"
#include "SceneRigStage_NamedParameter.h"
#include "SceneRigStage_NamedAnimation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigStage_NamedAnimation : public USceneRigStage_NamedParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Animation Parameter;
    
    USceneRigStage_NamedAnimation();
};

