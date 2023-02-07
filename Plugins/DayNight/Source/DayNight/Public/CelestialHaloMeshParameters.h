#pragma once
#include "CoreMinimal.h"
#include "CelestialHaloMeshParameters.generated.h"

USTRUCT(BlueprintType)
struct FCelestialHaloMeshParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MeshSlices;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeshInnerRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeshOuterRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUVAsAngleRadius;
    
    DAYNIGHT_API FCelestialHaloMeshParameters();
};

