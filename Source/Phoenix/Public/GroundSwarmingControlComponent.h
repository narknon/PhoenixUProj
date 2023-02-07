#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GroundSwarmingControlComponent.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UGroundSwarmingControlComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UGroundSwarmingControlComponent();
};

