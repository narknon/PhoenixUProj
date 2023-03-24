#pragma once
#include "CoreMinimal.h"
#include "SocialNavigatorController.h"
#include "SceneRigAIController.generated.h"

UCLASS(Blueprintable)
class ASceneRigAIController : public ASocialNavigatorController {
    GENERATED_BODY()
public:
    ASceneRigAIController(const FObjectInitializer& ObjectInitializer);
};

