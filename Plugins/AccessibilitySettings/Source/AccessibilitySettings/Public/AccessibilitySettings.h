#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EHighContrastMode.h"
#include "AccessibilitySettings.generated.h"

UCLASS(Blueprintable)
class ACCESSIBILITYSETTINGS_API UAccessibilitySettings : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAccessibilitySettings();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void HighContrastModeEnabled(EHighContrastMode HighContrastMode, bool& bEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetHighContrastMode(int32& HighContrastMode);
    
};

