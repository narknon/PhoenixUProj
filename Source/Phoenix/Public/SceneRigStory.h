#pragma once
#include "CoreMinimal.h"
#include "AnimDebugInfo.h"
#include "UObject/Object.h"
#include "SceneRigStory.generated.h"

class USceneRig;

UCLASS(Blueprintable)
class PHOENIX_API USceneRigStory : public UObject, public IAnimDebugInfo {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRig* StorySceneRig;
    
public:
    USceneRigStory();
    
    // Fix for true pure virtual functions not being implemented
};

