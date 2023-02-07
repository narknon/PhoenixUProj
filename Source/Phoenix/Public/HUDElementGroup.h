#pragma once
#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Blueprint/UserWidget.h"
#include "UIHUDGroups.h"
#include "HUDElementGroup.generated.h"

class UObject;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UHUDElementGroup : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<UIHUDGroups> MyGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESlateVisibility DesiredHiddenState;
    
public:
    UHUDElementGroup();
    UFUNCTION(BlueprintCallable)
    void ShowHUDElement(UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void HideHUDElement(UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    bool GetShouldBeHidden();
    
};

