#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_Object.generated.h"

class USceneRigParameterDefinition_Object;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigParameterBinding_Object : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_Object* Reference;
    
    FSceneRigParameterBinding_Object();
};

