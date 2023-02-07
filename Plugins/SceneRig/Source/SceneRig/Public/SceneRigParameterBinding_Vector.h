#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_Vector.generated.h"

class USceneRigParameterDefinition_Vector;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigParameterBinding_Vector : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_Vector* Reference;
    
    FSceneRigParameterBinding_Vector();
};

