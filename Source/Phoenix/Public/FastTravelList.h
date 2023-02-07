#pragma once
#include "CoreMinimal.h"
#include "PhoenixUserWidget.h"
#include "FastTravelList.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UFastTravelList : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UFastTravelList();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowEvent();
    
    UFUNCTION(BlueprintCallable)
    void Show();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetListTitle(const FString& Title);
    
    UFUNCTION(BlueprintCallable)
    bool IsListVisible();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HighlightListMenuItem(const FString& ItemName, bool bCallUnHovered);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideEvent();
    
    UFUNCTION(BlueprintCallable)
    void Hide();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnableItem(const FString& ItemName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DisableItem(const FString& ItemName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClearListMenuItems();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClearHighlightListMenuItem(bool bCallUnHovered);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClearAllHighlightedListMenuItems();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddListMenuItem(const FString& ItemName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddList(const TArray<FString>& ItemList);
    
};

