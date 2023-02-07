#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesInterpolants.h"
#include "LerpVolumesInterpolantsEvaluator.generated.h"

class ULerpVolumesPresistentContextData;

USTRUCT(BlueprintType)
struct FLerpVolumesInterpolantsEvaluator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLerpVolumesInterpolants Interpolants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULerpVolumesPresistentContextData* ContextData;
    
    LERPVOLUMES_API FLerpVolumesInterpolantsEvaluator();
};

