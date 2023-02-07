#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupDefinition.h"
#include "SceneAction_ActorMeshStates.h"
#include "SceneAction_ActorMeshFullSetup.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ActorMeshFullSetup : public USceneAction_ActorMeshStates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorMeshSetupDefinition Setup;
    
    USceneAction_ActorMeshFullSetup();
};

