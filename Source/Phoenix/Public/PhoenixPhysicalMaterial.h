#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MultiFX2Handle.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "EImpactTypes.h"
#include "SlidingData.h"
#include "PhoenixPhysicalMaterial.generated.h"

class AActor;
class UPhoenixPhysicalMaterial;
class UPrimitiveComponent;
class USurfaceImpactTypeData;

UCLASS(Blueprintable, CollapseCategories)
class UPhoenixPhysicalMaterial : public UPhysicalMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EImpactTypes ImpactType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlidingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpactDamageScale;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USurfaceImpactTypeData* BaseSurfaceImpactFile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<AActor*, FSlidingData> SlidingActorMap;
    
public:
    UPhoenixPhysicalMaterial();
    UFUNCTION(BlueprintCallable)
    bool WeatherAndLandscapePhysicalMaterialRemap(const FVector& ImpactLocation, UPrimitiveComponent* ImpactComponent, const AActor* Instigator, bool FootFall, UPhoenixPhysicalMaterial*& OutVfxRemapPPM, UPhoenixPhysicalMaterial*& OutSfxRemapPPM);
    
    UFUNCTION(BlueprintCallable)
    FMultiFX2Handle Impact(EImpactTypes InImpactType, const FVector& ImpactLocation, const FVector& ImpactNormal, const FVector& ImpactDirection, UPrimitiveComponent* ImpactComponent, AActor* Instigator, FName ImpactBone, float ImpactScale, float AudioImpactVelocity, const FVector& Velocity, bool UseRemap);
    
};

