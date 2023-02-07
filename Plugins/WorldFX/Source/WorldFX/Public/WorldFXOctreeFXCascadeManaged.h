#pragma once
#include "CoreMinimal.h"
#include "WorldFXOctreeFX.h"
#include "WorldFXOctreeFXCascadeManaged.generated.h"

class UParticleSystemComponent;

UCLASS(Blueprintable, NonTransient)
class WORLDFX_API UWorldFXOctreeFXCascadeManaged : public UWorldFXOctreeFX {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UParticleSystemComponent> ParticleComponent;
    
    UWorldFXOctreeFXCascadeManaged();
};

