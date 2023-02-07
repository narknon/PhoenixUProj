#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Object_SceneRigBoundActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UObject_SceneRigBoundActor : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoundObjectName;
    
    UObject_SceneRigBoundActor();
};

