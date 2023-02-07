#pragma once
#include "CoreMinimal.h"
#include "FastTravelTestEntry.generated.h"

USTRUCT(BlueprintType)
struct FFastTravelTestEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Locations;
    
    PHOENIX_API FFastTravelTestEntry();
};

