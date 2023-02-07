#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EventLocationResult.generated.h"

USTRUCT(BlueprintType)
struct FEventLocationResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LocationName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Guid;
    
    PHOENIX_API FEventLocationResult();
};

