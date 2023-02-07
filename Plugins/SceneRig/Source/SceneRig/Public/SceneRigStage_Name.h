#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterDefinition.h"
#include "SceneRigStage_Name.generated.h"

class UNameProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_Name : public FSceneRigStage_ParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNameProvider* DefaultProvider;
    
    FSceneRigStage_Name();
};

