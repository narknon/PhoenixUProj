#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_AvaAudioState.generated.h"

class USceneRigParameterDefinition_AvaAudioState;

USTRUCT(BlueprintType)
struct FSceneRigParameterBinding_AvaAudioState : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_AvaAudioState* Reference;
    
    PHOENIX_API FSceneRigParameterBinding_AvaAudioState();
};

