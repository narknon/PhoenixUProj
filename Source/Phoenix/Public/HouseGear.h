#pragma once
#include "CoreMinimal.h"
#include "GearName.h"
#include "HouseGear.generated.h"

USTRUCT(BlueprintType)
struct FHouseGear {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearName Gryffindor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearName Hufflepuff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearName Ravenclaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearName Slytherin;
    
    PHOENIX_API FHouseGear();
};

