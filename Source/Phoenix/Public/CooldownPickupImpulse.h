#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CooldownPickupImpulse.generated.h"

USTRUCT(BlueprintType)
struct FCooldownPickupImpulse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Min;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Max;
    
    PHOENIX_API FCooldownPickupImpulse();
};

