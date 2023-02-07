#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "LocalStencilBoundsHintComponentBase.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class STENCILMANAGER_API ULocalStencilBoundsHintComponentBase : public USceneComponent {
    GENERATED_BODY()
public:
    ULocalStencilBoundsHintComponentBase();
};

