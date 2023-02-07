#pragma once
#include "CoreMinimal.h"
#include "GeocentricOrbitResources.h"
#include "GeocentricOrbit.generated.h"

class UMaterialInstanceDynamic;
class USceneComponent;
class USplineComponent;
class USplineMeshComponent;

USTRUCT(BlueprintType)
struct FGeocentricOrbit {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGeocentricOrbitResources Resources;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* Spline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SplineMeshRoot;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> Extras;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> DynamicMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USplineMeshComponent*> SplineMeshes;
    
public:
    DAYNIGHT_API FGeocentricOrbit();
};

