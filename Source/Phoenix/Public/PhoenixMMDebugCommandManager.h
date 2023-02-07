#pragma once
#include "CoreMinimal.h"
#include "MastermindDebugCommandManager.h"
#include "PhoenixMMDebugCommandManager.generated.h"

class UObject;

UCLASS(Blueprintable)
class UPhoenixMMDebugCommandManager : public UMastermindDebugCommandManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObject*> CommandClasses;
    
public:
    UPhoenixMMDebugCommandManager();
};

