#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Letterbox_Base.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API ULetterbox_Base : public UUserWidget {
    GENERATED_BODY()
public:
    ULetterbox_Base();
    UFUNCTION(BlueprintCallable)
    void ShowLetterbox(bool Show);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowLetterbox(bool Show);
    
};

