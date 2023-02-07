#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigStage_ActorReference.h"
#include "CameraFixupActorAction.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class UCameraFixupActorAction : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_ActorReference Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UCameraFixupActorAction();
};

