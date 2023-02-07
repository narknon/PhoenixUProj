#pragma once
#include "CoreMinimal.h"
#include "SceneRigDialogTrackSectionData.h"
#include "SceneRigParameter.h"
#include "SceneRigParameter_DialogueEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigParameter_DialogueEvent : public USceneRigParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigDialogTrackSectionData Value;
    
    USceneRigParameter_DialogueEvent();
};

