#pragma once
#include "CoreMinimal.h"
#include "SceneRigBakeSequence.h"
#include "SceneRigObjectActionState.h"
#include "SceneRigAkAudioRTPCTrackSectionData.h"
#include "SceneActionState_AkAudioRTPC.generated.h"

UCLASS(Blueprintable)
class USceneActionState_AkAudioRTPC : public USceneRigObjectActionState, public ISceneRigBakeSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAkAudioRTPCTrackSectionData AkAudioRTPCData;
    
    USceneActionState_AkAudioRTPC();
    
    // Fix for true pure virtual functions not being implemented
};

