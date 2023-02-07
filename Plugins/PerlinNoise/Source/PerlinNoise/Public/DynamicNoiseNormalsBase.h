#pragma once
#include "CoreMinimal.h"
#include "DynamicNoiseTextureBase.h"
#include "DynamicNoiseNormalsBase.generated.h"

UCLASS(Abstract, Blueprintable)
class PERLINNOISE_API UDynamicNoiseNormalsBase : public UDynamicNoiseTextureBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NormalStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCurl;
    
    UDynamicNoiseNormalsBase();
};

