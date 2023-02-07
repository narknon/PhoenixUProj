#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WatchedConsoleVariable.generated.h"

UCLASS(Blueprintable)
class UWatchedConsoleVariable : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Variable;
    
    UWatchedConsoleVariable();
};

