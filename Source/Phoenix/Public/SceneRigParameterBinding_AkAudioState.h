#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_AkAudioState.generated.h"

class USceneRigParameterDefinition_AkAudioState;

USTRUCT(BlueprintType)
struct FSceneRigParameterBinding_AkAudioState : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_AkAudioState* Reference;
    
    PHOENIX_API FSceneRigParameterBinding_AkAudioState();
};

