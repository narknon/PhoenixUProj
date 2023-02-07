#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FXRule.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UFXRule : public UObject {
    GENERATED_BODY()
public:
    UFXRule();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool IsMatch() const;
    
};

