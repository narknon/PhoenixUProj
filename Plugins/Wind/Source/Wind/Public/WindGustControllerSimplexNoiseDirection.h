#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EWindGustCurveRemap.h"
#include "WindGustControllerSimplexNoise.h"
#include "WindGustControllerSimplexNoiseDirection.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWindGustControllerSimplexNoiseDirection : public UWindGustControllerSimplexNoise {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D NoiseRangeIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D GustRangeOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWindGustCurveRemap Remap;
    
    UWindGustControllerSimplexNoiseDirection();
};

