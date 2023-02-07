#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ParticleModuleLocationStaticMesh.h"
#include "SurfaceNormalParticleModule.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, EditInlineNew)
class USurfaceNormalParticleModule : public UParticleModuleLocationStaticMesh {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LimitToDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* FalloffCurve;
    
public:
    USurfaceNormalParticleModule();
};

