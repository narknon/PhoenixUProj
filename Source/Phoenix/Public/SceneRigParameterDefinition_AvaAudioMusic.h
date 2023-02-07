#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameterDefinition.h"
#include "SceneRigAvaAudioMusicTrackSectionData.h"
#include "SceneRigParameterDefinition_AvaAudioMusic.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRigParameterDefinition_AvaAudioMusic : public USceneRigParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAvaAudioMusicTrackSectionData DefaultEvent;
    
    USceneRigParameterDefinition_AvaAudioMusic();
};

