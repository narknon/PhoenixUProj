#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_AvaAudioMusic.generated.h"

class USceneRigParameterDefinition_AvaAudioMusic;

USTRUCT(BlueprintType)
struct FSceneRigParameterBinding_AvaAudioMusic : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_AvaAudioMusic* Reference;
    
    PHOENIX_API FSceneRigParameterBinding_AvaAudioMusic();
};

