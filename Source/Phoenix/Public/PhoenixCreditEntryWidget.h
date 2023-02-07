#pragma once
#include "CoreMinimal.h"
#include "CreditEntry.h"
#include "PhoenixUserWidget.h"
#include "PhoenixCreditEntryWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UPhoenixCreditEntryWidget : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCreditEntryAnimationEnded);
    
    UPhoenixCreditEntryWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCreditEntryInfo(const FCreditEntry CreditEntry);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCreditEntryAnimProgress(const float Progress);
    
};

