#include "PhoenixPhysicalMaterial.h"

class AActor;
class UPhoenixPhysicalMaterial;
class UPrimitiveComponent;

bool UPhoenixPhysicalMaterial::WeatherAndLandscapePhysicalMaterialRemap(const FVector& ImpactLocation, UPrimitiveComponent* ImpactComponent, const AActor* Instigator, bool FootFall, UPhoenixPhysicalMaterial*& OutVfxRemapPPM, UPhoenixPhysicalMaterial*& OutSfxRemapPPM) {
    return false;
}

FMultiFX2Handle UPhoenixPhysicalMaterial::Impact(EImpactTypes InImpactType, const FVector& ImpactLocation, const FVector& ImpactNormal, const FVector& ImpactDirection, UPrimitiveComponent* ImpactComponent, AActor* Instigator, FName ImpactBone, float ImpactScale, float AudioImpactVelocity, const FVector& Velocity, bool UseRemap) {
    return FMultiFX2Handle{};
}

UPhoenixPhysicalMaterial::UPhoenixPhysicalMaterial() {
    this->ImpactType = EImpactTypes::Default;
    this->SlidingTime = 0.50f;
    this->ImpactDamageScale = 1.00f;
    this->BaseSurfaceImpactFile = NULL;
}

