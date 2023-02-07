#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GenericStepWidget.generated.h"

class UImage;

UCLASS(Blueprintable, EditInlineNew)
class UGenericStepWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* checkmark;
    
    UGenericStepWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UntickBox(UImage* Image);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TickBox(UImage* Image);
    
};

