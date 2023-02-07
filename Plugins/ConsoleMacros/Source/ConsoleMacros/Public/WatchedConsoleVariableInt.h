#pragma once
#include "CoreMinimal.h"
#include "WatchedConsoleVariable.h"
#include "WatchedConsoleVariableDynamicDelegateIntDelegate.h"
#include "WatchedConsoleVariableInt.generated.h"

UCLASS(Blueprintable)
class CONSOLEMACROS_API UWatchedConsoleVariableInt : public UWatchedConsoleVariable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWatchedConsoleVariableDynamicDelegateInt ChangedEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    UWatchedConsoleVariableInt();
};

