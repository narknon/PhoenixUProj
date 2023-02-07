#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RemapScalarRange.generated.h"

USTRUCT(BlueprintType)
struct FRemapScalarRange {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D InputRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D OutputRange;
    
    PHOENIX_API FRemapScalarRange();
};

