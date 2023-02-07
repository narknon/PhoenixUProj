#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameter.h"
#include "SceneRigAvaAudioMusicTrackSectionData.h"
#include "SceneRigParameter_AvaAudioMusic.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRigParameter_AvaAudioMusic : public USceneRigParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAvaAudioMusicTrackSectionData Value;
    
    USceneRigParameter_AvaAudioMusic();
};

