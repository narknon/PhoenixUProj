#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesName.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    LERPVOLUMES_API FLerpVolumesName();
};

