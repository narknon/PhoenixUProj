#pragma once
#include "CoreMinimal.h"
#include "HUDElementGroup.h"
#include "ComboHelperHud.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UComboHelperHud : public UHUDElementGroup {
    GENERATED_BODY()
public:
    UComboHelperHud();
    UFUNCTION(BlueprintCallable)
    void SpellSuccess();
    
    UFUNCTION(BlueprintCallable)
    void SpellFailure();
    
    UFUNCTION(BlueprintCallable)
    void ShowComboHelper(const bool bShow);
    
    UFUNCTION(BlueprintCallable)
    void SetRequiredSpells(const TArray<FString>& SpellNames);
    
    UFUNCTION(BlueprintCallable)
    void ResetCombo();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpellSucceeded(const int32 NumSucceeded);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpellFailed(const int32 NumSucceeded);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowComboHelperChanged(const bool bShow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRequiredSpellsChanged(const TArray<FString>& SpellNames, const int32 NumSpells);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnComboReset();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnComboCompleted();
    
};

