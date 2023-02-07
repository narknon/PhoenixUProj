#pragma once
#include "CoreMinimal.h"
#include "Components/WidgetSwitcher.h"
#include "WidgetActiveEventDelegate.h"
#include "AsyncWidgetSwitcher.generated.h"

class UAsyncLoadWrapper;
class UUserWidget;

UCLASS(Blueprintable)
class UAsyncWidgetSwitcher : public UWidgetSwitcher {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldPreloadAll;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWidgetActiveEvent OnActiveWidgetDisplayable;
    
    UAsyncWidgetSwitcher();
    UFUNCTION(BlueprintCallable)
    void SetParent(UUserWidget* NewParent);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnActiveItemLoaded(UAsyncLoadWrapper* Item);
    
};

