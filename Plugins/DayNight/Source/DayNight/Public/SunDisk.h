#pragma once
#include "CoreMinimal.h"
#include "SunDiskOverrides.h"
#include "CelestialDiskMeshParameters.h"
#include "SunDiskComputedState.h"
#include "SunDiskCorona.h"
#include "SunDiskParameters.h"
#include "SunDisk.generated.h"

class UMaterial;
class UMaterialInstanceDynamic;
class UProceduralMeshComponent;

USTRUCT(BlueprintType)
struct DAYNIGHT_API FSunDisk {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UProceduralMeshComponent* MeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterial* BaseMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* DynamicMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSunDiskParameters Parameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSunDiskCorona Corona;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSunDiskOverrides OverrideState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float OverrideStateLerpAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSunDiskComputedState CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCelestialDiskMeshParameters MeshParameters;
    
    FSunDisk();
};

