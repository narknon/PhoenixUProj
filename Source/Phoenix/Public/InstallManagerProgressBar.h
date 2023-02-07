#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EInstallManagerState.h"
#include "InstallManagerProgressBar.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UInstallManagerProgressBar : public UUserWidget {
    GENERATED_BODY()
public:
    UInstallManagerProgressBar();
    UFUNCTION(BlueprintCallable)
    void StartPendingLoad();
    
    UFUNCTION(BlueprintCallable)
    float GetInstallPercentage();
    
    UFUNCTION(BlueprintCallable)
    FString GetInstallMessageText();
    
    UFUNCTION(BlueprintCallable)
    EInstallManagerState GetInstallManagerState();
    
};

