#pragma once
#include "CoreMinimal.h"
#include "AnimatedLightClusterComponent.h"
#include "AnimatedLightClusterComponentChildOfLight.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ANIMATEDLIGHTS_API UAnimatedLightClusterComponentChildOfLight : public UAnimatedLightClusterComponent {
    GENERATED_BODY()
public:
    UAnimatedLightClusterComponentChildOfLight();
};

