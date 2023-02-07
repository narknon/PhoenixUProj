#pragma once
#include "CoreMinimal.h"
#include "CelestialDiskMeshParameters.generated.h"

USTRUCT(BlueprintType)
struct FCelestialDiskMeshParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MeshSlices;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeshRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUVAsAngleRadius;
    
    DAYNIGHT_API FCelestialDiskMeshParameters();
};

