#pragma once
#include "CoreMinimal.h"
#include "DynamicNoiseNormalsBase.h"
#include "OctaveNoiseParams.h"
#include "DynamicNoiseOctaveNormals.generated.h"

UCLASS(Blueprintable)
class PERLINNOISE_API UDynamicNoiseOctaveNormals : public UDynamicNoiseNormalsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOctaveNoiseParams NoiseParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeFactor;
    
    UDynamicNoiseOctaveNormals();
};

