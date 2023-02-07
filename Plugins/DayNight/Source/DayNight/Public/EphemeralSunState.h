#pragma once
#include "CoreMinimal.h"
#include "TopographicDirection.h"
#include "EphemeralSunState.generated.h"

USTRUCT(BlueprintType)
struct FEphemeralSunState : public FTopographicDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DiskScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Visibility;
    
    DAYNIGHT_API FEphemeralSunState();
};

