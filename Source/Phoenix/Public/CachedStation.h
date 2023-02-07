#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CachedStationPath.h"
#include "CachedStation.generated.h"

USTRUCT(BlueprintType)
struct FCachedStation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ParentLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FCachedStationPath> PathsToOtherLocations;
    
    PHOENIX_API FCachedStation();
};

