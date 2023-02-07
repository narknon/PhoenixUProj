#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateColor.h"
#include "Blueprint/UserWidget.h"
#include "CheckboxStateChangeDelegateDelegate.h"
#include "CheckboxWidget.generated.h"

class UCheckBox;
class UPhoenixTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class UCheckboxWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PreTranslateText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsChecked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CheckboxLabelText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateColor CompletedColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateColor CurrentColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateColor FutureColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCheckBox* TheCheckbox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* CheckboxTextBlock;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCheckboxStateChangeDelegate OnCheckboxStateChange;
    
    UCheckboxWidget();
    UFUNCTION(BlueprintCallable)
    void StateChanged(bool State);
    
    UFUNCTION(BlueprintCallable)
    void SetProperties(FText Label, int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void SetCheckboxOnOff(FText Label, bool checked);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
};

