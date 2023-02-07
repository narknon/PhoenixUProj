#pragma once
#include "CoreMinimal.h"
#include "SceneRigAvaAudioMusicTrackSectionData.h"
#include "SceneRigParameterBinding_AvaAudioMusic.h"
#include "ActionParameter_AvaAudioMusic.generated.h"

USTRUCT(BlueprintType)
struct FActionParameter_AvaAudioMusic {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_AvaAudioMusic BoundParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAvaAudioMusicTrackSectionData DefaultEvent;
    
    PHOENIX_API FActionParameter_AvaAudioMusic();
};

