#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorRotationSpring.h"
#include "CameraStackBehaviorRotationSpringVideoCapture.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorRotationSpringVideoCapture : public UCameraStackBehaviorRotationSpring {
    GENERATED_BODY()
public:
    UCameraStackBehaviorRotationSpringVideoCapture();
};

