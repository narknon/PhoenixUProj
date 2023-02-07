#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TopographicDirection.generated.h"

USTRUCT(BlueprintType)
struct FTopographicDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AzimuthDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AltitudeDegrees;
    
    DAYNIGHT_API FTopographicDirection();
};

