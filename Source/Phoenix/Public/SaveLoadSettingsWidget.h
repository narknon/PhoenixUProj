#pragma once
#include "CoreMinimal.h"
#include "SettingsTabEventDelegate.h"
#include "SettingsTabWidget.h"
#include "SaveLoadSettingsWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USaveLoadSettingsWidget : public USettingsTabWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSettingsTabEvent OnLoadButtonClicked;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSettingsTabEvent OnSaveButtonClicked;
    
    USaveLoadSettingsWidget();
protected:
    UFUNCTION(BlueprintCallable)
    bool RestartFromLastSave();
    
    UFUNCTION(BlueprintCallable)
    void QuitGame();
    
    UFUNCTION(BlueprintCallable)
    void ExitToMain();
    
    UFUNCTION(BlueprintCallable)
    void ActivateHoverdrone();
    
};

