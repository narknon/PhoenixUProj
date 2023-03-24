#pragma once
#include "CoreMinimal.h"
#include "SocialNavigatorController.h"
#include "WalkToLocationAutomationAIController.generated.h"

UCLASS(Blueprintable)
class AWalkToLocationAutomationAIController : public ASocialNavigatorController {
    GENERATED_BODY()
public:
    AWalkToLocationAutomationAIController(const FObjectInitializer& ObjectInitializer);
};

