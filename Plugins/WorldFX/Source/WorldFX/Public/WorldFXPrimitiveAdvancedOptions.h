#pragma once
#include "CoreMinimal.h"
#include "WorldFXPrimitiveAdvancedOptions.generated.h"

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXPrimitiveAdvancedOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TranslucencySortPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TranslucencySortDistanceOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bReceivesDecals: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bReceivesWeatherDecals: 1;
    
    FWorldFXPrimitiveAdvancedOptions();
};

