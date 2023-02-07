#pragma once
#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "DebugMapVolumeComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDebugMapVolumeComponent : public UProceduralMeshComponent {
    GENERATED_BODY()
public:
    UDebugMapVolumeComponent();
};

