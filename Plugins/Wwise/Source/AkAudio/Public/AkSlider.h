#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Types/SlateEnums.h"
#include "Styling/SlateTypes.h"
#include "Components/Widget.h"
#include "Components/Widget.h"
#include "AkOnFloatValueChangedEventDelegate.h"
#include "AkPropertyToControl.h"
#include "AkWwiseItemToControl.h"
#include "OnItemDropDetectedDelegate.h"
#include "OnPropertyDropDetectedDelegate.h"
#include "AkSlider.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Editor)
class AKAUDIO_API UAkSlider : public UWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWidget::FGetFloat ValueDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSliderStyle WidgetStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EOrientation> Orientation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor SliderBarColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor SliderHandleColor;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IndentHandle;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Locked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StepSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsFocusable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAkPropertyToControl ThePropertyToControl;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAkWwiseItemToControl ItemToControl;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAkOnFloatValueChangedEvent OnValueChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemDropDetected OnItemDropped;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPropertyDropDetected OnPropertyDropped;
    
    UAkSlider();
    UFUNCTION(BlueprintCallable)
    void SetValue(float InValue);
    
    UFUNCTION(BlueprintCallable)
    void SetStepSize(float InValue);
    
    UFUNCTION(BlueprintCallable)
    void SetSliderHandleColor(FLinearColor InValue);
    
    UFUNCTION(BlueprintCallable)
    void SetSliderBarColor(FLinearColor InValue);
    
    UFUNCTION(BlueprintCallable)
    void SetLocked(bool InValue);
    
    UFUNCTION(BlueprintCallable)
    void SetIndentHandle(bool InValue);
    
    UFUNCTION(BlueprintCallable)
    void SetAkSliderItemProperty(const FString& ItemProperty);
    
    UFUNCTION(BlueprintCallable)
    void SetAkSliderItemId(const FGuid& ItemId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetValue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetAkSliderItemProperty() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGuid GetAkSliderItemId() const;
    
};

