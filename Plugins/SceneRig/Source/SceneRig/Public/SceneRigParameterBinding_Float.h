#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_Float.generated.h"

class USceneRigParameterDefinition_Float;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigParameterBinding_Float : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_Float* Reference;
    
    FSceneRigParameterBinding_Float();
};

