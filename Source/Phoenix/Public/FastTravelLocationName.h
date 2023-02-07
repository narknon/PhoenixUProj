#pragma once
#include "CoreMinimal.h"
#include "FastTravelLocationName.generated.h"

USTRUCT(BlueprintType)
struct FFastTravelLocationName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    PHOENIX_API FFastTravelLocationName();
};

