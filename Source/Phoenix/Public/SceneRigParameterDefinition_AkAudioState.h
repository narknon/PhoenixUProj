#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameterDefinition.h"
#include "SceneRigAkAudioStateTrackSectionData.h"
#include "SceneRigParameterDefinition_AkAudioState.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRigParameterDefinition_AkAudioState : public USceneRigParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAkAudioStateTrackSectionData DefaultEvent;
    
    USceneRigParameterDefinition_AkAudioState();
};

