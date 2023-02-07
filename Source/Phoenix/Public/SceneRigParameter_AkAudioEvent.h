#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameter.h"
#include "SceneRigAkAudioEventTrackSectionData.h"
#include "SceneRigParameter_AkAudioEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRigParameter_AkAudioEvent : public USceneRigParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAkAudioEventTrackSectionData Value;
    
    USceneRigParameter_AkAudioEvent();
};

