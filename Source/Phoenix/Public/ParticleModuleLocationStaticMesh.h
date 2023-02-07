#pragma once
#include "CoreMinimal.h"
#include "Particles/Location/ParticleModuleLocationBase.h"
#include "Distributions/DistributionFloat.h"
#include "ParticleModuleLocationStaticMesh.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UParticleModuleLocationStaticMesh : public UParticleModuleLocationBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Velocity: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRawDistributionFloat VelocityScale;
    
    UParticleModuleLocationStaticMesh();
};

