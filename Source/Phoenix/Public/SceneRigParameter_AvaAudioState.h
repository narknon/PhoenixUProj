#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameter.h"
#include "SceneRigAvaAudioStateTrackSectionData.h"
#include "SceneRigParameter_AvaAudioState.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRigParameter_AvaAudioState : public USceneRigParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAvaAudioStateTrackSectionData Value;
    
    USceneRigParameter_AvaAudioState();
};

