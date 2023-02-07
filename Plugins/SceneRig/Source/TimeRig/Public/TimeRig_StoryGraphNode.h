#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TimeRig_StoryGraphNode.generated.h"

class UTimeRig_StoryGraphEdge;
class UTimeRig_StoryGraphNode;

UCLASS(Abstract, Blueprintable)
class TIMERIG_API UTimeRig_StoryGraphNode : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTimeRig_StoryGraphNode*> ParentNodes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTimeRig_StoryGraphNode*> ChildrenNodes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UTimeRig_StoryGraphNode*, UTimeRig_StoryGraphEdge*> Edges;
    
    UTimeRig_StoryGraphNode();
};

