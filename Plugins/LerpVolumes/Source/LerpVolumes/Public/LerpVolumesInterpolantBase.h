#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesInterpolantBase.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesInterpolantBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HermesMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WWiseRTPC;
    
    LERPVOLUMES_API FLerpVolumesInterpolantBase();
};

