#pragma once
#include "CoreMinimal.h"
#include "RacerTime.generated.h"

USTRUCT(BlueprintType)
struct FRacerTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RacerName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RaceTime;
    
    PHOENIX_API FRacerTime();
};

