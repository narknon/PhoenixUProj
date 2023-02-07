#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameterDefinition.h"
#include "SceneRigAkAudioEventTrackSectionData.h"
#include "SceneRigParameterDefinition_AkAudioEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRigParameterDefinition_AkAudioEvent : public USceneRigParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAkAudioEventTrackSectionData DefaultEvent;
    
    USceneRigParameterDefinition_AkAudioEvent();
};

