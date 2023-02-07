#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_Int.generated.h"

class USceneRigParameterDefinition_Int;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigParameterBinding_Int : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_Int* Reference;
    
    FSceneRigParameterBinding_Int();
};

