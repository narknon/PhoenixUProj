#pragma once
#include "CoreMinimal.h"
#include "WorldBaseHeights.generated.h"

USTRUCT(BlueprintType)
struct FWorldBaseHeights {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CloudsZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpHeightFogZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AtmosphereZ;
    
    GLOBALLIGHTRIG_API FWorldBaseHeights();
};

