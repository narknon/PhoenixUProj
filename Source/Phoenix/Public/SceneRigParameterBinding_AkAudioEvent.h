#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_AkAudioEvent.generated.h"

class USceneRigParameterDefinition_AkAudioEvent;

USTRUCT(BlueprintType)
struct FSceneRigParameterBinding_AkAudioEvent : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_AkAudioEvent* Reference;
    
    PHOENIX_API FSceneRigParameterBinding_AkAudioEvent();
};

