#pragma once
#include "CoreMinimal.h"
#include "VegetationInteractionComponentBiped.h"
#include "VegetationInteractionComponentCreature.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UVegetationInteractionComponentCreature : public UVegetationInteractionComponentBiped {
    GENERATED_BODY()
public:
    UVegetationInteractionComponentCreature();
};

