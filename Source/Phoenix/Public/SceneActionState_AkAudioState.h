#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneRigAkAudioStateTrackSectionData.h"
#include "SceneActionState_AkAudioState.generated.h"

UCLASS(Blueprintable)
class USceneActionState_AkAudioState : public USceneRigActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAkAudioStateTrackSectionData AkAudioStateData;
    
    USceneActionState_AkAudioState();
};

