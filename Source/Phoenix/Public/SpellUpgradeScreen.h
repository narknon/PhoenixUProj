#pragma once
#include "CoreMinimal.h"
#include "TabPageWidget.h"
#include "SpellUpgradeScreen.generated.h"

class UIconButtonWidget;
class UUniformGridPanel;

UCLASS(Blueprintable, EditInlineNew)
class USpellUpgradeScreen : public UTabPageWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UIconButtonWidget*> Spells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUniformGridPanel* SpellPanel;
    
    USpellUpgradeScreen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAttachWand();
    
};

