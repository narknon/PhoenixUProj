#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CachedStationPath.generated.h"

USTRUCT(BlueprintType)
struct FCachedStationPath {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> PathPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PathLength;
    
    PHOENIX_API FCachedStationPath();
};

