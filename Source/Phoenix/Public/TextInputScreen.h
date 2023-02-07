#pragma once
#include "CoreMinimal.h"
#include "Screen.h"
#include "TextInputCancelledEventDelegate.h"
#include "TextInputTextConfirmedEventDelegate.h"
#include "TextInputScreen.generated.h"

class UCreatureState;

UCLASS(Blueprintable, EditInlineNew)
class UTextInputScreen : public UScreen {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTextInputTextConfirmedEvent OnTextConfirmed;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTextInputCancelledEvent OnDialogCancelled;
    
    UTextInputScreen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPopupTitle(const FString& PopupTitle);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCreatureState(UCreatureState* CreatureState);
    
};

