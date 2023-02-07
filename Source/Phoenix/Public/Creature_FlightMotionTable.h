#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CreatureLandingMotionData.h"
#include "CreatureTakeoffMotionData.h"
#include "ECreatureLandingType.h"
#include "Creature_FlightMotionTable.generated.h"

UCLASS(Blueprintable)
class UCreature_FlightMotionTable : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ECreatureLandingType, FCreatureLandingMotionData> LandingMotionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCreatureTakeoffMotionData> TakeoffMotionData;
    
    UCreature_FlightMotionTable();
};

