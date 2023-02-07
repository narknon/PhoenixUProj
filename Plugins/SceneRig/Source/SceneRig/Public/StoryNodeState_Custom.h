#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StoryNodeState_Custom.generated.h"

class AStoryGraphActor;
class UStoryNode_Custom;

UCLASS(Blueprintable)
class SCENERIG_API UStoryNodeState_Custom : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AStoryGraphActor* OwningActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStoryNode_Custom* Definition;
    
    UStoryNodeState_Custom();
};

