#pragma once
#include "CoreMinimal.h"
#include "OdcFlags.generated.h"

USTRUCT(BlueprintType)
struct FOdcFlags {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Bits;
    
public:
    ODYSSEYRUNTIME_API FOdcFlags();
};

