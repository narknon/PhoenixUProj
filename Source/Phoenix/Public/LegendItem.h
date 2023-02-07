#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateColor.h"
#include "EInputDeviceUsed.h"
#include "LegendItemData.h"
#include "PhoenixUserWidget.h"
#include "LegendItem.generated.h"

class ULegendItem;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API ULegendItem : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLegendItemHoldReleaseEvent, ULegendItem*, LegendItem, bool, HoldWasCompleted);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLegendItemHoldReleaseEvent HoldReleasedEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLegendItemData mLegendItemData;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mIsHolding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mDisabledState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mHoldTimeRemaining;
    
public:
    ULegendItem();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateFillMeterStyle(EInputDeviceUsed UsedInputDevice);
    
public:
    UFUNCTION(BlueprintCallable)
    void StopHolding();
    
    UFUNCTION(BlueprintCallable)
    void StartHolding();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTextColor(FSlateColor InColor);
    
    UFUNCTION(BlueprintCallable)
    void SetProgressUsed(const bool ProgressUsed);
    
    UFUNCTION(BlueprintCallable)
    void SetProgress(const float Progress);
    
    UFUNCTION(BlueprintCallable)
    void SetLegendItemData(const FLegendItemData& LegendItemData);
    
    UFUNCTION(BlueprintCallable)
    void SetHoldDuration(const float NewHoldDuration);
    
    UFUNCTION(BlueprintCallable)
    void SetDisabledState(const bool Disabled);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ProgressUsedChanged(const bool ProgressUsed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ProgressChanged(const float Progress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void LegendItemDataChanged(const FString& ButtonString, const FString& TextString, const bool TextStringIsLocalized);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLegendItemData GetLegendItemData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DisabledStateChanged(const bool Disabled);
    
};

