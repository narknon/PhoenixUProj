#pragma once
#include "CoreMinimal.h"
#include "TimeRigParentElement.h"
#include "SceneRigActionState.h"
#include "SceneActionState_SpawnActor.generated.h"

class AActor;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_SpawnActor : public USceneRigActionState, public ITimeRigParentElement {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
public:
    USceneActionState_SpawnActor();
    
    // Fix for true pure virtual functions not being implemented
};

