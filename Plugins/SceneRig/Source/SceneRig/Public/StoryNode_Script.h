#pragma once
#include "CoreMinimal.h"
#include "TimeRig_StoryGraphNode.h"
#include "SceneRigScriptContainer.h"
#include "StoryNode_Script.generated.h"

UCLASS(Abstract, Blueprintable)
class SCENERIG_API UStoryNode_Script : public UTimeRig_StoryGraphNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigScriptContainer Script;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool RegisteredAvailableNextLineIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> AvailableNextLineIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName RegisteredLastLineID;
    
    UStoryNode_Script();
};

