#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InterpolatableExponentialHeightFogComponent.generated.h"

UCLASS(Blueprintable, Deprecated, NotPlaceable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class EXPHEIGHTFOGVOLUMES_API UDEPRECATED_InterpolatableExponentialHeightFogComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UDEPRECATED_InterpolatableExponentialHeightFogComponent();
};

