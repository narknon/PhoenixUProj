#pragma once
#include "CoreMinimal.h"
#include "SocialTravelerController.h"
#include "SocialSplineController.generated.h"

UCLASS(Blueprintable)
class SOCIALDISPLAY_API ASocialSplineController : public ASocialTravelerController {
    GENERATED_BODY()
public:
    ASocialSplineController(const FObjectInitializer& ObjectInitializer);
};

