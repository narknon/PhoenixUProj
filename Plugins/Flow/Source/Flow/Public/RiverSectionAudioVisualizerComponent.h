#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RiverSectionAudioVisualizerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FLOW_API URiverSectionAudioVisualizerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    URiverSectionAudioVisualizerComponent();
};

