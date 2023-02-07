#pragma once
#include "CoreMinimal.h"
#include "Screen.h"
#include "StartPageWidget.generated.h"

class UObject;
class UPhoenixUserWidget;

UCLASS(Blueprintable, EditInlineNew)
class UStartPageWidget : public UScreen {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanProceed;
    
    UStartPageWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowLoginButton(const bool bShow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetProfileString(const FString& ProfileName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetLoginButtonString(const FString& LoginButtonString);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIsLoggedIn(const bool bIsLoggedIn);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetHydraString(const FString& ProfileName);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnUserProfileChange(const UObject* i_caller, const FString& UserName);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnStartPageOutroStarted(UPhoenixUserWidget* PhoenixWidget, int32 OutroType);
    
    UFUNCTION(BlueprintCallable)
    void OnStartPageOutroEnded(UPhoenixUserWidget* PhoenixWidget, int32 OutroType);
    
    UFUNCTION(BlueprintCallable)
    void OnStartPageIntroStarted(UPhoenixUserWidget* PhoenixWidget, int32 IntroType);
    
};

