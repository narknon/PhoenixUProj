#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FluidSimActor.generated.h"

class UFluidSimComponent;
class UFluidSimEmitterComponent;

UCLASS(Blueprintable, MinimalAPI)
class AFluidSimActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFluidSimComponent* FluidSimComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFluidSimEmitterComponent* FluidSimEmitter;
    
    AFluidSimActor();
};

