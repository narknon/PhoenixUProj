#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameterDefinition.h"
#include "SceneRigAvaAudioStateTrackSectionData.h"
#include "SceneRigParameterDefinition_AvaAudioState.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRigParameterDefinition_AvaAudioState : public USceneRigParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAvaAudioStateTrackSectionData DefaultEvent;
    
    USceneRigParameterDefinition_AvaAudioState();
};

