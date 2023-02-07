#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MercunaNavSeedComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MERCUNA_API UMercunaNavSeedComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UMercunaNavSeedComponent();
};

