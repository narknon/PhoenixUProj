#pragma once
#include "CoreMinimal.h"
#include "AnimatedLightClusterComponent.h"
#include "AnimatedLightClusterComponentAuto.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ANIMATEDLIGHTS_API UAnimatedLightClusterComponentAuto : public UAnimatedLightClusterComponent {
    GENERATED_BODY()
public:
    UAnimatedLightClusterComponentAuto();
};

