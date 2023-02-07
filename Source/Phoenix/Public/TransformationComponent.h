#pragma once
#include "CoreMinimal.h"
#include "StateEffectComponent.h"
#include "TransformationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTransformationComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
    UTransformationComponent();
};

