#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_AkAudioRTPC.generated.h"

class USceneRigParameterDefinition_AkAudioRTPC;

USTRUCT(BlueprintType)
struct FSceneRigParameterBinding_AkAudioRTPC : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_AkAudioRTPC* Reference;
    
    PHOENIX_API FSceneRigParameterBinding_AkAudioRTPC();
};

