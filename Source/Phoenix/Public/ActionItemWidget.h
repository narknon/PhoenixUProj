#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionItemWidget.generated.h"

class UImage;

UCLASS(Blueprintable, EditInlineNew)
class UActionItemWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UActionItemWidget();
    UFUNCTION(BlueprintCallable)
    void ExecuteAction();
    
    UFUNCTION(BlueprintCallable)
    void CollectItemData(int32 LoadoutIndex, int32 ItemIndex, UImage* ItemIcon);
    
};

