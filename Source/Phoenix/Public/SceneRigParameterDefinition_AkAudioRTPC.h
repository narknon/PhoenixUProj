#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameterDefinition.h"
#include "SceneRigAkAudioRTPCTrackSectionData.h"
#include "SceneRigParameterDefinition_AkAudioRTPC.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRigParameterDefinition_AkAudioRTPC : public USceneRigParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAkAudioRTPCTrackSectionData DefaultEvent;
    
    USceneRigParameterDefinition_AkAudioRTPC();
};

