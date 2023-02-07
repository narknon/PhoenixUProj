#pragma once
#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "EPauseMenuPage.h"
#include "IconButtonWidget.h"
#include "FieldGuideButtonBase.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UFieldGuideButtonBase : public UIconButtonWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPauseMenuPage MenuTab;
    
public:
    UFieldGuideButtonBase();
    UFUNCTION(BlueprintCallable)
    void SetNewItemIndicatorVisibility();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetLockedState(bool IsLocked);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetItemIndicatorVisibility(ESlateVisibility InVisibility);
    
    UFUNCTION(BlueprintCallable)
    void LockButton(bool ShouldLock);
    
    UFUNCTION(BlueprintCallable)
    bool GetLockedState();
    
};

