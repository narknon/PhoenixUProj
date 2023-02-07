#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameter.h"
#include "SceneRigAkAudioStateTrackSectionData.h"
#include "SceneRigParameter_AkAudioState.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRigParameter_AkAudioState : public USceneRigParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAkAudioStateTrackSectionData Value;
    
    USceneRigParameter_AkAudioState();
};

