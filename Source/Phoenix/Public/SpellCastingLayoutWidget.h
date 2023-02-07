#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnterSpellModeDelegateDelegate.h"
#include "ExitSpellModeDelegateDelegate.h"
#include "SpellSelectedDelegateDelegate.h"
#include "SpellCastingLayoutWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpellCastingLayoutWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ActiveLayout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* ParentWidget;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpellSelectedDelegate OnNewSpellSelected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnterSpellModeDelegate OnEnterSpellMode;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExitSpellModeDelegate OnExitSpellMode;
    
    USpellCastingLayoutWidget();
    UFUNCTION(BlueprintCallable)
    void SpellSelected();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeactivateLayout();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActivateLayout();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitSpells();
    
    UFUNCTION(BlueprintCallable)
    void EnterSpellMode(bool InSpellMode);
    
};

