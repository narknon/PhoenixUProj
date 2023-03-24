#pragma once
#include "CoreMinimal.h"
#include "SocialAIController.h"
#include "SocialTravelerController.generated.h"

UCLASS(Blueprintable)
class SOCIALDISPLAY_API ASocialTravelerController : public ASocialAIController {
    GENERATED_BODY()
public:
    ASocialTravelerController(const FObjectInitializer& ObjectInitializer);
};

