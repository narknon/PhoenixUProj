#pragma once
#include "CoreMinimal.h"
#include "SceneRigDialogTrackSectionData.h"
#include "SceneRigParameterBinding_DialogueEvent.h"
#include "ActionParameter_DialogueEvent.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FActionParameter_DialogueEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_DialogueEvent BoundParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigDialogTrackSectionData DefaultEvent;
    
    FActionParameter_DialogueEvent();
};

