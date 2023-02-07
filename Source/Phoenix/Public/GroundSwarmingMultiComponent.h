#pragma once
#include "CoreMinimal.h"
#include "GroundSwarmingControlComponent.h"
#include "GroundSwarmingDeathVolume.h"
#include "GroundSwarmingExternalForce.h"
#include "GroundSwarmingForceModifier.h"
#include "GroundSwarmingMultiComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UGroundSwarmingMultiComponent : public UGroundSwarmingControlComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGroundSwarmingExternalForce ExternalForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGroundSwarmingForceModifier ForceModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGroundSwarmingDeathVolume DeathVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseExternalForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseForceModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDeathVolume;
    
    UGroundSwarmingMultiComponent();
};

