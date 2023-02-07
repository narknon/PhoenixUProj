#pragma once
#include "CoreMinimal.h"
#include "Screen.h"
#include "RichPaperScreen.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URichPaperScreen : public UScreen {
    GENERATED_BODY()
public:
    URichPaperScreen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetRichPaperID(const FString& RichPaperID);
    
};

