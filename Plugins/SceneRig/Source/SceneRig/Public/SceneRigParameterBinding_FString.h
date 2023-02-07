#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_FString.generated.h"

class USceneRigParameterDefinition_FString;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigParameterBinding_FString : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_FString* Reference;
    
    FSceneRigParameterBinding_FString();
};

