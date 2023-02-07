#pragma once
#include "CoreMinimal.h"
#include "GroundSwarmingControlComponent.h"
#include "GroundSwarmingDeathVolume.h"
#include "GroundSwarmingDeathVolumeComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UGroundSwarmingDeathVolumeComponent : public UGroundSwarmingControlComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGroundSwarmingDeathVolume DeathVolume;
    
    UGroundSwarmingDeathVolumeComponent();
};

