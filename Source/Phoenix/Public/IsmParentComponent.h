#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "IsmParentComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UIsmParentComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UIsmParentComponent();
};

