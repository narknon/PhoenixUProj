#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneRigAvaAudioStateTrackSectionData.h"
#include "SceneActionState_AvaAudioState.generated.h"

UCLASS(Blueprintable)
class USceneActionState_AvaAudioState : public USceneRigActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAvaAudioStateTrackSectionData AvaAudioStateData;
    
    USceneActionState_AvaAudioState();
};

