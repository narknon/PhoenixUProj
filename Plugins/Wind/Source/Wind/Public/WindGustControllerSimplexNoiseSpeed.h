#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EWindGustCurveRemap -FallbackName=EWindGustCurveRemap
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EWindGustSpeedOp -FallbackName=EWindGustSpeedOp
#include "EWindGustCurveRemap.h"
#include "EWindGustSpeedOp.h"
#include "WindGustControllerSimplexNoise.h"
#include "WindGustControllerSimplexNoiseSpeed.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWindGustControllerSimplexNoiseSpeed : public UWindGustControllerSimplexNoise {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D NoiseRangeIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D GustRangeOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWindGustCurveRemap Remap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWindGustSpeedOp SpeedOp;
    
    UWindGustControllerSimplexNoiseSpeed();
};

