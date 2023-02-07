#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CameraStackFramingLocationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class CAMERASTACK_API UCameraStackFramingLocationComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UCameraStackFramingLocationComponent();
};

