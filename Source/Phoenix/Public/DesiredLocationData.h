#pragma once
#include "CoreMinimal.h"
#include "DesiredLocationData.generated.h"

USTRUCT(BlueprintType)
struct FDesiredLocationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DesiredLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLocationAvailable;
    
    PHOENIX_API FDesiredLocationData();
};

