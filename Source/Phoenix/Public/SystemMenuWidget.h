#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "EUMGInputAction.h"
#include "TabPageWidget.h"
#include "SystemMenuWidget.generated.h"

class UPopupScreen;

UCLASS(Blueprintable, EditInlineNew)
class USystemMenuWidget : public UTabPageWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasShownExitConfirmation;
    
public:
    USystemMenuWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowLoadSaveResultPopup(const FString& ResultMessage, float Duration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowGraphicsConfirmDialog(float Duration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool SettingsNeedExitConfirmed(FString& OutConfirmTitle, FString& OutConfirmDesc);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnExitPopupGone();
    
    UFUNCTION(BlueprintCallable)
    void OnExitPopupDismissed(UPopupScreen* Popup, int32 ConfirmationResult);
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleConfirmExitDialog(EUMGInputAction ExitAction, EInputEvent ExitEvent, const FString& TitleText, const FString& DescText);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteSave(const int32 CharacterID);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteLoad(const FString& Filename, const int32 CharacterID);
    
};

