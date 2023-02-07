#pragma once
#include "CoreMinimal.h"
#include "InputActionHoldInfo.h"
#include "LegendItemData.h"
#include "Screen.h"
#include "PopupScreen.generated.h"

class UPhoenixUserWidget;
class UPopupScreen;
class UUserWidget;

UCLASS(Blueprintable, EditInlineNew)
class UPopupScreen : public UScreen {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPopupRemovedEvent);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPopupButtonEvent, UPopupScreen*, PopupScreen, int32, CompletionActionIndex);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPopupButtonEvent PopupButtonPressCompletedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPopupRemovedEvent PopupRemovedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPopupButtonEvent PopupClosedEvent;
    
private:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 PopupID;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FInputActionHoldInfo> CachedCompletionActions;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCachedUsesWaitIndicator;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bPausedTheGame;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bAutoCloseOnButtonPress;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bPopupClosedEventSent;
    
public:
    UPopupScreen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPopupUsesWaitIndicator(const bool bUsesWaitIndicator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPopupTitle(const FString& TitleString);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPopupLegendItems(const TArray<FLegendItemData>& LegendItems);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPopupDescription(const FString& DescriptionString, bool isTranslated);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPopupContentWidget(const UUserWidget* ContentWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPopupCompletionActions(const TArray<FInputActionHoldInfo>& CompletionActions);
    
    UFUNCTION(BlueprintCallable)
    void SetCachedUsesWaitIndicator(const bool bUsesWaitIndicator);
    
    UFUNCTION(BlueprintCallable)
    void SetCachedCompletionActions(const TArray<FInputActionHoldInfo>& CompletionActions);
    
    UFUNCTION(BlueprintCallable)
    void SetAutoCloseOnButtonPress(const bool bInAutoCloseOnButtonPress);
    
    UFUNCTION(BlueprintCallable)
    void PopupButtonPressCompleted(const int32 CompletionActionIndex);
    
    UFUNCTION(BlueprintCallable)
    void OpenPopup(const bool bPauseTheGame);
    
    UFUNCTION(BlueprintCallable)
    void OnPopupOutroEnded(UPhoenixUserWidget* PhoenixWidget, int32 OutroType);
    
    UFUNCTION(BlueprintCallable)
    int32 GetPopupID();
    
    UFUNCTION(BlueprintCallable)
    void ClosePopup(const int32 CompletionActionIndex);
    
};

