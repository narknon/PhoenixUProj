#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterValue.h"
#include "SceneRigStage_ObjectValue.generated.h"

class UObjectProvider;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStage_ObjectValue : public USceneRigStage_ParameterValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectProvider* Provider;
    
    USceneRigStage_ObjectValue();
};

