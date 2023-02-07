#pragma once
#include "CoreMinimal.h"
#include "CineCameraComponent.h"
#include "CameraStackCineComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class CAMERASTACK_API UCameraStackCineComponent : public UCineCameraComponent {
    GENERATED_BODY()
public:
    UCameraStackCineComponent();
};

