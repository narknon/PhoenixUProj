#pragma once
#include "CoreMinimal.h"
#include "AnimatedLightParametersComponentBase.h"
#include "AnimatedLightParametersComponentAuto.generated.h"

class ULightComponent;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ANIMATEDLIGHTS_API UAnimatedLightParametersComponentAuto : public UAnimatedLightParametersComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULightComponent* ForceLightComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseForceLightComponent;
    
    UAnimatedLightParametersComponentAuto();
};

