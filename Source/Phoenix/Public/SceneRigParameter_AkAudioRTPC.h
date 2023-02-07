#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameter.h"
#include "SceneRigAkAudioRTPCTrackSectionData.h"
#include "SceneRigParameter_AkAudioRTPC.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRigParameter_AkAudioRTPC : public USceneRigParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAkAudioRTPCTrackSectionData Value;
    
    USceneRigParameter_AkAudioRTPC();
};

