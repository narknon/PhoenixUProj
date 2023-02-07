#pragma once
#include "CoreMinimal.h"
#include "TabPageWidget.h"
#include "SettingsTabWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USettingsTabWidget : public UTabPageWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NeedsExitConfirmed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ConfirmExitTitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ConfirmExitDesc;
    
    USettingsTabWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitForSettingsLocation(bool IsInFieldGuide);
    
};

