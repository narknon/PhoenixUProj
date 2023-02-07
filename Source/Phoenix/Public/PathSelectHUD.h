#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PathSelectHUD.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPathSelectHUD : public UUserWidget {
    GENERATED_BODY()
public:
    UPathSelectHUD();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Start();
    
};

