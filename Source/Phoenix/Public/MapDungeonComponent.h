#pragma once
#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "MapDungeonComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMapDungeonComponent : public UProceduralMeshComponent {
    GENERATED_BODY()
public:
    UMapDungeonComponent();
};

