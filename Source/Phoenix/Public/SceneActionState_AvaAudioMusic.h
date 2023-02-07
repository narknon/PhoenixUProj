#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneRigAvaAudioMusicTrackSectionData.h"
#include "SceneActionState_AvaAudioMusic.generated.h"

UCLASS(Blueprintable)
class USceneActionState_AvaAudioMusic : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAvaAudioMusicTrackSectionData AvaAudioMusicData;
    
    USceneActionState_AvaAudioMusic();
};

