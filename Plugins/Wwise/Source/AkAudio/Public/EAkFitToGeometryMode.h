#pragma once
#include "CoreMinimal.h"
#include "EAkFitToGeometryMode.generated.h"

UENUM(BlueprintType)
enum class EAkFitToGeometryMode : uint8 {
    OrientedBox,
    AlignedBox,
    ConvexPolyhedron,
};

