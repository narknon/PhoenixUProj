#pragma once
#include "CoreMinimal.h"
#include "WorldFXCascadeSystemParamBase.h"
#include "WorldFXCascadeSystemParamScalar.generated.h"

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXCascadeSystemParamScalar : public FWorldFXCascadeSystemParamBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scalar;
    
    FWorldFXCascadeSystemParamScalar();
};

