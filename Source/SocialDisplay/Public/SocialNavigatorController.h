#pragma once
#include "CoreMinimal.h"
#include "SocialTravelerController.h"
#include "SocialNavigatorController.generated.h"

UCLASS(Blueprintable)
class SOCIALDISPLAY_API ASocialNavigatorController : public ASocialTravelerController {
    GENERATED_BODY()
public:
    ASocialNavigatorController(const FObjectInitializer& ObjectInitializer);
};

