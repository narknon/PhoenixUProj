#pragma once
#include "CoreMinimal.h"
#include "UMGFocusWidget.h"
#include "EMenuReaderInterruptType.h"
#include "PhoenixUserWidget.generated.h"

class UObject;
class UPhoenixUserWidget;

UCLASS(Blueprintable, EditInlineNew)
class UPhoenixUserWidget : public UUMGFocusWidget {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPhoenixUserWidgetIntEvent, UPhoenixUserWidget*, PhoenixUserWidget, int32, IntParam);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPhoenixUserWidgetIntEvent IntroStartedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPhoenixUserWidgetIntEvent IntroEndedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPhoenixUserWidgetIntEvent OutroStartedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPhoenixUserWidgetIntEvent OutroEndedEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultIntroDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultOutroDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InterruptMenuReaderOnDestruct;
    
    UPhoenixUserWidget();
    UFUNCTION(BlueprintCallable)
    void TriggerOutro(const int32 OutroType);
    
    UFUNCTION(BlueprintCallable)
    void TriggerIntro(const int32 IntroType);
    
    UFUNCTION(BlueprintCallable)
    void TriggerCustomOutro(const int32 OutroType, const float OutroDuration);
    
    UFUNCTION(BlueprintCallable)
    void TriggerCustomIntro(const int32 IntroType, const float IntroDuration);
    
    UFUNCTION(BlueprintCallable)
    void ReadMenu(const int32 DepthLevel, const EMenuReaderInterruptType InterruptType, UObject* InterruptOwnerFilter);
    
    UFUNCTION(BlueprintCallable)
    void OverrideInitialIntroType(const int32 IntroType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnOutroStarted(const int32 OutroType, const float OutroDuration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnOutroEnded(const int32 OutroType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnIntroStarted(const int32 IntroType, const float IntroDuration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnIntroEnded(const int32 IntroType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTransitionInProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentTransitionAnIntro() const;
    
    UFUNCTION(BlueprintCallable)
    void InterruptMenuReader(const EMenuReaderInterruptType InterruptType, UObject* InterruptOwnerFilter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentTransitionType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentTransitionProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TArray<FString> GatherMenuReaderStrings(const int32 DepthLevel) const;
    
};

