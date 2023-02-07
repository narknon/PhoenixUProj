#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "WaterCollisionComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FLOW_API UWaterCollisionComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UWaterCollisionComponent();
};

