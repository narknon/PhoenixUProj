#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterValue.h"
#include "SceneRigStage_AnimationValue.generated.h"

class UAnimationProvider;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStage_AnimationValue : public USceneRigStage_ParameterValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationProvider* Provider;
    
    USceneRigStage_AnimationValue();
};

