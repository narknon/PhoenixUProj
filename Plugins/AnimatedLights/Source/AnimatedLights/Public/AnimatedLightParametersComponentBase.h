#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AnimatedLightParametersComponentBase.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ANIMATEDLIGHTS_API UAnimatedLightParametersComponentBase : public USceneComponent {
    GENERATED_BODY()
public:
    UAnimatedLightParametersComponentBase();
};

