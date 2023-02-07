#pragma once
#include "CoreMinimal.h"
#include "NoMountZoneAvoidanceParams.generated.h"

USTRUCT(BlueprintType)
struct FNoMountZoneAvoidanceParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FrontTraceLengthGrounded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FrontTraceLengthGrounded_Jog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FrontTraceLengthGrounded_Sprint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FrontTraceLengthGrounded_Charge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FrontTraceLengthFlying;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FrontTraceLengthFlying_Slow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FrontTraceLengthFlying_Fast;
    
    PHOENIX_API FNoMountZoneAvoidanceParams();
};

