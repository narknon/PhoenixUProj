#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PopoutWidget.generated.h"

class UPhoenixTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class UPopoutWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* PopoutWidgetTEST;
    
    UPopoutWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
};

