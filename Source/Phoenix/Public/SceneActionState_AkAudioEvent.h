#pragma once
#include "CoreMinimal.h"
#include "SceneRigBakeSequence.h"
#include "SceneRigObjectActionState.h"
#include "SceneRigAkAudioEventTrackSectionData.h"
#include "SceneActionState_AkAudioEvent.generated.h"

UCLASS(Blueprintable)
class USceneActionState_AkAudioEvent : public USceneRigObjectActionState, public ISceneRigBakeSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAkAudioEventTrackSectionData AkAudioEventData;
    
    USceneActionState_AkAudioEvent();
    
    // Fix for true pure virtual functions not being implemented
};

