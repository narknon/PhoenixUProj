#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HoverDroneHUD.generated.h"

UCLASS(Blueprintable, NonTransient)
class HOVERDRONE_API AHoverDroneHUD : public AHUD {
    GENERATED_BODY()
public:
    AHoverDroneHUD();
};

