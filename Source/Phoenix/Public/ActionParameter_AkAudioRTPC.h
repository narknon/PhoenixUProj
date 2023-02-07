#pragma once
#include "CoreMinimal.h"
#include "SceneRigAkAudioRTPCTrackSectionData.h"
#include "SceneRigParameterBinding_AkAudioRTPC.h"
#include "ActionParameter_AkAudioRTPC.generated.h"

USTRUCT(BlueprintType)
struct FActionParameter_AkAudioRTPC {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_AkAudioRTPC BoundParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAkAudioRTPCTrackSectionData DefaultRTPC;
    
    PHOENIX_API FActionParameter_AkAudioRTPC();
};

