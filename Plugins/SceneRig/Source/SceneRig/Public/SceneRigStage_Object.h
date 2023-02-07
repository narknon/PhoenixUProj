#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterDefinition.h"
#include "SceneRigStage_Object.generated.h"

class UObjectProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_Object : public FSceneRigStage_ParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectProvider* DefaultProvider;
    
    FSceneRigStage_Object();
};

