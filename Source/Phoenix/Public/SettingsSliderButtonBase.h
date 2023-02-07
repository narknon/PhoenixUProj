#pragma once
#include "CoreMinimal.h"
#include "AvaUserWidget.h"
#include "SettingsSliderButtonBase.generated.h"

class USlider;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API USettingsSliderButtonBase : public UAvaUserWidget {
    GENERATED_BODY()
public:
    USettingsSliderButtonBase();
protected:
    UFUNCTION(BlueprintCallable)
    void SetMouseUsesStep_Internal(USlider* Slider, bool MouseUsesStep);
    
};

