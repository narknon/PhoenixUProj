#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PortraitCallOutAttachComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPortraitCallOutAttachComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPortraitCallOutAttachComponent();
};

