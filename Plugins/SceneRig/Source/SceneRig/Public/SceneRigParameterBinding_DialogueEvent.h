#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_DialogueEvent.generated.h"

class USceneRigParameterDefinition_DialogueEvent;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigParameterBinding_DialogueEvent : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_DialogueEvent* Reference;
    
    FSceneRigParameterBinding_DialogueEvent();
};

