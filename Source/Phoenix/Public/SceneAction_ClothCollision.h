#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_ClothCollision.generated.h"

class UActorProvider;
class UPhysicsAsset;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ClothCollision : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* CollisionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicsAsset* PhysicsAsset;
    
    USceneAction_ClothCollision();
};

