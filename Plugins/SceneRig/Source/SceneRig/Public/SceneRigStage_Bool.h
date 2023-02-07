#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterDefinition.h"
#include "SceneRigStage_Bool.generated.h"

class UBoolProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_Bool : public FSceneRigStage_ParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* DefaultProvider;
    
    FSceneRigStage_Bool();
};

