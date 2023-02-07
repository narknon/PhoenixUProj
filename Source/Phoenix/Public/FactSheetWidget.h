#pragma once
#include "CoreMinimal.h"
#include "TabPageWidget.h"
#include "FactSheetWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UFactSheetWidget : public UTabPageWidget {
    GENERATED_BODY()
public:
    UFactSheetWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool SetFactSheetData(const FString& ItemName);
    
};

