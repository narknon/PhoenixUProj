#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneActionState_SpawnFromDOV.generated.h"

class AActor;

UCLASS(Abstract, Blueprintable)
class USceneActionState_SpawnFromDOV : public USceneRigActionState {
    GENERATED_BODY()
public:
    USceneActionState_SpawnFromDOV();
    UFUNCTION(BlueprintCallable)
    void SpawnCallback(AActor* SpawnedActor, const FName& GroupName);
    
};

