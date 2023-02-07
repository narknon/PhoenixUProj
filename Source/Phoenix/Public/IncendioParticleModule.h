#pragma once
#include "CoreMinimal.h"
#include "ESpawnAreaEnum.h"
#include "ParticleModuleLocationStaticMesh.h"
#include "IncendioParticleModule.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, EditInlineNew)
class UIncendioParticleModule : public UParticleModuleLocationStaticMesh {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpawnAreaEnum SpawnArea;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* FalloffCurve;
    
public:
    UIncendioParticleModule();
};

