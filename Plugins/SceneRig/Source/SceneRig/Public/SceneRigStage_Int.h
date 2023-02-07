#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterDefinition.h"
#include "SceneRigStage_Int.generated.h"

class UIntProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_Int : public FSceneRigStage_ParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UIntProvider* DefaultProvider;
    
    FSceneRigStage_Int();
};

