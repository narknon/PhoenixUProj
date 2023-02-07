#pragma once
#include "CoreMinimal.h"
#include "ESurfaceFogType.h"
#include "SurfaceFogParameters.generated.h"

USTRUCT(BlueprintType)
struct FSurfaceFogParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESurfaceFogType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Intensity;
    
    WEATHER_API FSurfaceFogParameters();
};

