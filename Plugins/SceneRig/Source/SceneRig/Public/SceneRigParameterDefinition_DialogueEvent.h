#pragma once
#include "CoreMinimal.h"
#include "SceneRigDialogTrackSectionData.h"
#include "SceneRigParameterDefinition.h"
#include "SceneRigParameterDefinition_DialogueEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigParameterDefinition_DialogueEvent : public USceneRigParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigDialogTrackSectionData DefaultEvent;
    
    USceneRigParameterDefinition_DialogueEvent();
};

