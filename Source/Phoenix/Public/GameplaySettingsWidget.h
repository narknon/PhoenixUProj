#pragma once
#include "CoreMinimal.h"
#include "TabPageWidget.h"
#include "GameplaySettingsWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UGameplaySettingsWidget : public UTabPageWidget {
    GENERATED_BODY()
public:
    UGameplaySettingsWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SuppressDifficultySetting();
    
};

