#pragma once
#include "CoreMinimal.h"
#include "LegendItemData.h"
#include "Screen.h"
#include "InGameMenuScreen.generated.h"

class UPageStack;

UCLASS(Blueprintable, EditInlineNew)
class UInGameMenuScreen : public UScreen {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPageStack* ThePageStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NeedsAutosave;
    
public:
    UInGameMenuScreen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetButtonLegend(const TArray<FLegendItemData>& Legend);
    
    UFUNCTION(BlueprintCallable)
    void MarkNeedsAutosave();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExitPauseMenu(bool SkipFade);
    
};

