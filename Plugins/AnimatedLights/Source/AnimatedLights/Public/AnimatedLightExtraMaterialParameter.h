#pragma once
#include "CoreMinimal.h"
#include "AnimatedLightExtraParameterRuntime.h"
#include "AnimatedLightExtraMaterialParameter.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct ANIMATEDLIGHTS_API FAnimatedLightExtraMaterialParameter : public FAnimatedLightExtraParameterRuntime {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMaterialInstanceDynamic> Material;
    
    FAnimatedLightExtraMaterialParameter();
};

