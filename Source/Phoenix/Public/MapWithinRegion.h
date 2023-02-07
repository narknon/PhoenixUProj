#pragma once
#include "CoreMinimal.h"
#include "MapWithinRegion.generated.h"

class APhoenixMapRegion;

USTRUCT(BlueprintType)
struct FMapWithinRegion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhoenixMapRegion* Region;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhoenixMapRegion* SubRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhoenixMapRegion* LevelRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhoenixMapRegion* InnerLevelRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RegionName;
    
    PHOENIX_API FMapWithinRegion();
};

