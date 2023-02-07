#pragma once
#include "CoreMinimal.h"
#include "WatchedConsoleVariable.h"
#include "WatchedConsoleVariableDynamicDelegateFloatDelegate.h"
#include "WatchedConsoleVariableFloat.generated.h"

UCLASS(Blueprintable)
class CONSOLEMACROS_API UWatchedConsoleVariableFloat : public UWatchedConsoleVariable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWatchedConsoleVariableDynamicDelegateFloat ChangedEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UWatchedConsoleVariableFloat();
};

