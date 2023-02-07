#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TaskData.h"
#include "TrackingInfoWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UTrackingInfoWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisplayDuration;
    
public:
    UTrackingInfoWidget();
    UFUNCTION(BlueprintCallable)
    void OnDisplayInputReleased();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsExtended();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsDisplayed();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DisplayTrackerInfo(const FString& TrackerTitle, const TArray<FTaskData>& TaskData, const FString& ExtendedDesc, const FString& IconName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DisplayExtendedInfo();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CollapseTrackerInfo();
    
};

