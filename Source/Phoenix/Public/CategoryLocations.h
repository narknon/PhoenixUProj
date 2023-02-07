#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CategoryLocations.generated.h"

USTRUCT(BlueprintType)
struct FCategoryLocations {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRandomStream Randomizer;
    
    PHOENIX_API FCategoryLocations();
};

