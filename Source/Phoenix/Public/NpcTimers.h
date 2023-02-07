#pragma once
#include "CoreMinimal.h"
#include "NpcFxTimer.h"
#include "NpcTimer.h"
#include "NpcTimers.generated.h"

USTRUCT(BlueprintType)
struct FNpcTimers {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FNpcTimer> NpcTimers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FNpcFxTimer> NpcFxTimers;
    
public:
    PHOENIX_API FNpcTimers();
};

