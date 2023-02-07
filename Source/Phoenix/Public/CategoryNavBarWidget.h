#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CategoryNavBarWidget.generated.h"

class UIconButtonWidget;
class UImage;

UCLASS(Blueprintable, EditInlineNew)
class UCategoryNavBarWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FText> CategoryNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurCategoryIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* BackgroundImage;
    
    UCategoryNavBarWidget();
    UFUNCTION(BlueprintCallable)
    void PrevCategory();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnhover(const UIconButtonWidget* hoveredButton);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHover(const UIconButtonWidget* hoveredButton);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnClick(int32 SelectedCategory);
    
    UFUNCTION(BlueprintCallable)
    void OnCategoryButtonUnHover(UIconButtonWidget* Button);
    
    UFUNCTION(BlueprintCallable)
    void OnCategoryButtonHover(UIconButtonWidget* Button);
    
    UFUNCTION(BlueprintCallable)
    void OnCategoryButtonClicked(UIconButtonWidget* Button);
    
    UFUNCTION(BlueprintCallable)
    void NextCategory();
    
    UFUNCTION(BlueprintCallable)
    void InitializeButton(UIconButtonWidget* Button, FText buttonIcon);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    int32 GetIndexOfButton(UIconButtonWidget* Button);
    
    UFUNCTION(BlueprintCallable)
    FText GetCurrentCategory();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UIconButtonWidget* GetButtonByIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void AddCategory(FText NewCategory);
    
};

