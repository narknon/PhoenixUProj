#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EPointOfInterestState.h"
#include "PointOfInterest.generated.h"

USTRUCT(BlueprintType)
struct FPointOfInterest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PointOfInterestId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DiscoverDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPointOfInterestState State;
    
    PHOENIX_API FPointOfInterest();
};

