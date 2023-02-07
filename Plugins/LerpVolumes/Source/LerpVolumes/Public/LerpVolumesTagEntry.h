#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesTagEntry.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesTagEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString StringValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameValue;
    
    LERPVOLUMES_API FLerpVolumesTagEntry();
};

