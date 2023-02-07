#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AzimuthAltitudeDegrees.h"
#include "GeocentricOrbitPoint.generated.h"

USTRUCT(BlueprintType)
struct FGeocentricOrbitPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TopographicDir;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Up;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Right;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAzimuthAltitudeDegrees AzimuthAltitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBasisValid;
    
    DAYNIGHT_API FGeocentricOrbitPoint();
};

