#pragma once
#include "CoreMinimal.h"
#include "WatchedConsoleVariable.h"
#include "WatchedConsoleVariableDynamicDelegateBoolDelegate.h"
#include "WatchedConsoleVariableBool.generated.h"

UCLASS(Blueprintable)
class CONSOLEMACROS_API UWatchedConsoleVariableBool : public UWatchedConsoleVariable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWatchedConsoleVariableDynamicDelegateBool ChangedEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValue;
    
    UWatchedConsoleVariableBool();
};

