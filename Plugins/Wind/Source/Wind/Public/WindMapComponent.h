#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "WindMapComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WIND_API UWindMapComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UWindMapComponent();
};

