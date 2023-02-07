#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ETutorialPosition.h"
#include "HintDynanmicDelegateDelegate.h"
#include "Hint.generated.h"

UCLASS(Blueprintable)
class UHint : public UObject {
    GENERATED_BODY()
public:
    UHint();
    UFUNCTION(BlueprintCallable)
    void GameLogicExpressionChanged(bool bNewValue);
    
    UFUNCTION(BlueprintCallable)
    void Blueprint_QueueForDisplay(const float InInitialWaitTime, const float InOnScreenTime, const float InOffScreenTime, ETutorialPosition InHintPosition, const FHintDynanmicDelegate& InShouldDisplayDelegate);
    
};

