#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GearName.h"
#include "HouseGear.h"
#include "AvatarHouseGearMappings.generated.h"

UCLASS(Blueprintable)
class UAvatarHouseGearMappings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGearName, FHouseGear> HouseGearMapping;
    
    UAvatarHouseGearMappings();
};

