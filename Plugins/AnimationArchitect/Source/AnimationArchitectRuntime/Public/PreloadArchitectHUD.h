#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PreloadArchitectHUD.generated.h"

UCLASS(Blueprintable, NonTransient)
class ANIMATIONARCHITECTRUNTIME_API APreloadArchitectHUD : public AHUD {
    GENERATED_BODY()
public:
    APreloadArchitectHUD();
    UFUNCTION(BlueprintCallable)
    void TogglePreloadArchitectHUD();
    
};

