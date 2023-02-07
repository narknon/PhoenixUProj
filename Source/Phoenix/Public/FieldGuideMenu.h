#pragma once
#include "CoreMinimal.h"
#include "EUMGInputAction.h"
#include "LegendItemData.h"
#include "Screen.h"
#include "FieldGuideMenu.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UFieldGuideMenu : public UScreen {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NeedsAutosave;
    
public:
    UFieldGuideMenu();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateMenuLegend(const TArray<FLegendItemData>& NewData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MenuReadLegend();
    
    UFUNCTION(BlueprintCallable)
    void MarkNeedsAutosave();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ChangeMenuPage(EUMGInputAction MenuPage);
    
};

