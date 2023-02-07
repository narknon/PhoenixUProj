#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupName.h"
#include "SceneAction_ActorMeshStates.h"
#include "SceneAction_ActorMeshSetup.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ActorMeshSetup : public USceneAction_ActorMeshStates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorMeshSetupName Setup;
    
    USceneAction_ActorMeshSetup();
};

