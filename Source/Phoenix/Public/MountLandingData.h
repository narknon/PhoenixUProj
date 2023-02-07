#pragma once
#include "CoreMinimal.h"
#include "MountLandingData.generated.h"

USTRUCT(BlueprintType)
struct FMountLandingData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TouchdownTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreTouchdownSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostTouchdownSpeed;
    
    PHOENIX_API FMountLandingData();
};

