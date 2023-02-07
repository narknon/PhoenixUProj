#pragma once
#include "CoreMinimal.h"
#include "Screen.h"
#include "RevelioPageScreen.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API URevelioPageScreen : public UScreen {
    GENERATED_BODY()
public:
    URevelioPageScreen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetRevelioPageID(FName PageID);
    
};

