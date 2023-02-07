#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigStage_ParameterReference.h"
#include "SceneRigStageParameterBlock.generated.h"

class USceneRigStage_ParameterValue;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStageParameterBlock : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FSceneRigStage_ParameterReference, USceneRigStage_ParameterValue*> ParameterMap;
    
    USceneRigStageParameterBlock();
};

