#pragma once
#include "CoreMinimal.h"
#include "ENvidiaLatencyMode.h"
#include "NvidiaLatencyModeInfo.generated.h"

USTRUCT(BlueprintType)
struct FNvidiaLatencyModeInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENvidiaLatencyMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LocStr;
    
    PHOENIX_API FNvidiaLatencyModeInfo();
};

