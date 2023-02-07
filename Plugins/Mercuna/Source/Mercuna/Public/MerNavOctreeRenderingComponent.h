#pragma once
#include "CoreMinimal.h"
#include "Components/MeshComponent.h"
#include "MerNavOctreeRenderingComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMerNavOctreeRenderingComponent : public UMeshComponent {
    GENERATED_BODY()
public:
    UMerNavOctreeRenderingComponent();
};

