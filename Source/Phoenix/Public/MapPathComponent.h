#pragma once
#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "MapPathComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMapPathComponent : public UProceduralMeshComponent {
    GENERATED_BODY()
public:
    UMapPathComponent();
};

