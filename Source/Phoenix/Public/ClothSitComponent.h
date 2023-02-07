#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ClothSitComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UClothSitComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UClothSitComponent();
};

