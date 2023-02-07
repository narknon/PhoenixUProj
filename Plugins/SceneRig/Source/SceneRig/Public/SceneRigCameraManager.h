#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConversationAssetTracker.h"
#include "SceneRigCameraManager.generated.h"

class UObject;

UCLASS(Blueprintable)
class SCENERIG_API ASceneRigCameraManager : public AActor, public IConversationAssetTracker {
    GENERATED_BODY()
public:
    ASceneRigCameraManager();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static AActor* GetActiveSceneRigCamera(const UObject* WorldContextObject);
    
    
    // Fix for true pure virtual functions not being implemented
};

