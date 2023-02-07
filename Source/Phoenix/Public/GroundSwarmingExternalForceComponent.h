#pragma once
#include "CoreMinimal.h"
#include "GroundSwarmingControlComponent.h"
#include "GroundSwarmingExternalForce.h"
#include "GroundSwarmingExternalForceComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UGroundSwarmingExternalForceComponent : public UGroundSwarmingControlComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGroundSwarmingExternalForce ExternalForce;
    
    UGroundSwarmingExternalForceComponent();
};

