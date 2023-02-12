#pragma once
#include "CoreMinimal.h"
#include "AkMeshType.generated.h"

UENUM(BlueprintType)
enum class AkMeshType : uint8 {
    StaticMesh,
    CollisionMesh,
};

