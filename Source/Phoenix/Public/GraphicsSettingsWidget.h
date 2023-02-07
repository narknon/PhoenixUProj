#pragma once
#include "CoreMinimal.h"
#include "GraphicsConfirmDialogRequestedDelegate.h"
#include "SettingsTabEventDelegate.h"
#include "SettingsTabWidget.h"
#include "GraphicsSettingsWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UGraphicsSettingsWidget : public USettingsTabWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGraphicsConfirmDialogRequested OnConfirmDialogRequested;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSettingsTabEvent OnCalibrationSelected;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSettingsTabEvent OnHDRCalibrationSelected;
    
    UGraphicsSettingsWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SyncDisplaySettings();
    
    UFUNCTION(BlueprintCallable)
    void RevertVideoChanges();
    
    UFUNCTION(BlueprintCallable)
    void AcceptVideoChanges();
    
};

