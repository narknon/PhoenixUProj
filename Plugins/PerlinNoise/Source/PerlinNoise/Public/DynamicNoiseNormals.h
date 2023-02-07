#pragma once
#include "CoreMinimal.h"
#include "DynamicNoiseNormalsBase.h"
#include "NoiseParams2D.h"
#include "DynamicNoiseNormals.generated.h"

UCLASS(Blueprintable)
class PERLINNOISE_API UDynamicNoiseNormals : public UDynamicNoiseNormalsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNoiseParams2D NoiseParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeFactor;
    
    UDynamicNoiseNormals();
};

