#pragma once
#include "CoreMinimal.h"
#include "PhoenixUserWidget.h"
#include "AvaUserWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAvaUserWidget : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UAvaUserWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
};

