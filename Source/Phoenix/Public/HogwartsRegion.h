#pragma once
#include "CoreMinimal.h"
#include "HogwartsRegion.generated.h"

class UBeaconInfo;

USTRUCT(BlueprintType)
struct FHogwartsRegion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBeaconInfo* Region;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> RegionsIcons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RequiredLock1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBeaconInfo* AlertBeacon;
    
    PHOENIX_API FHogwartsRegion();
};

