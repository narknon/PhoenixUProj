#pragma once
#include "CoreMinimal.h"
#include "WorldFXCascadeSystemParamBase.h"
#include "WorldFXCascadeSystemParamScalarRand.generated.h"

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXCascadeSystemParamScalarRand : public FWorldFXCascadeSystemParamBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scalar_Low;
    
    FWorldFXCascadeSystemParamScalarRand();
};

