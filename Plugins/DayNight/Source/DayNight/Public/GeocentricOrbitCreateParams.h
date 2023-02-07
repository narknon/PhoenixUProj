#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GeocentricOrbitCreateBaseParams.h"
#include "TopographicObserver.h"
#include "GeocentricOrbitCreateParams.generated.h"

USTRUCT(BlueprintType)
struct FGeocentricOrbitCreateParams : public FGeocentricOrbitCreateBaseParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTopographicObserver TopographicPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime StartDateTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Samples;
    
    DAYNIGHT_API FGeocentricOrbitCreateParams();
};

