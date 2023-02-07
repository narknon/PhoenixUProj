#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ECreatureLandingType.h"
#include "MountLandingData.h"
#include "Creature_MountLandingDynamics.generated.h"

UCLASS(Blueprintable)
class UCreature_MountLandingDynamics : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ECreatureLandingType, FMountLandingData> LandingDataMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LandingMaxAcceleration;
    
    UCreature_MountLandingDynamics();
};

