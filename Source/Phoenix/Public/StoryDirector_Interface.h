#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SceneRigParameters.h"
#include "StoryDirector_Interface.generated.h"

class UObject;

UINTERFACE(Blueprintable)
class UStoryDirector_Interface : public UInterface {
    GENERATED_BODY()
};

class IStoryDirector_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StoryEnded(UObject* inSceneRigStory);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetupStorySceneRigProp(FSceneRigParameters& outParameters);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetupStorySceneRigConnection(FSceneRigParameters& outParameters, int32 InConnectionIndex, int32 InChannel);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ParticipantFinishedExit(UObject* inParticipant, int32 InConnectionIndex, FName inSocialSemantic, bool inTestForMovementMode);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ParticipantFinishedEnter(UObject* inParticipant, int32 InConnectionIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void NotifyAllStoriesOfEvent(FName InEventName);
    
};

