#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_Transform.generated.h"

class USceneRigParameterDefinition_Transform;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigParameterBinding_Transform : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_Transform* Reference;
    
    FSceneRigParameterBinding_Transform();
};

