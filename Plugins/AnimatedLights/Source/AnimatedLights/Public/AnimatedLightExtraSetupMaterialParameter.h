#pragma once
#include "CoreMinimal.h"
#include "AnimatedLightExtraParameter.h"
#include "AnimatedLightExtraSetupMaterialParameter.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct ANIMATEDLIGHTS_API FAnimatedLightExtraSetupMaterialParameter : public FAnimatedLightExtraParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* Material;
    
    FAnimatedLightExtraSetupMaterialParameter();
};

