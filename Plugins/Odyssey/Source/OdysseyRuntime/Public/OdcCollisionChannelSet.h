#pragma once
#include "CoreMinimal.h"
#include "OdcCollisionChannelSet.generated.h"

USTRUCT(BlueprintType)
struct ODYSSEYRUNTIME_API FOdcCollisionChannelSet {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ChannelBitmask;
    
public:
    FOdcCollisionChannelSet();
};

