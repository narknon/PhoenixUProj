#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_Bool.generated.h"

class USceneRigParameterDefinition_Bool;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigParameterBinding_Bool : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_Bool* Reference;
    
    FSceneRigParameterBinding_Bool();
};

