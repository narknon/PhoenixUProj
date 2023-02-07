#pragma once
#include "CoreMinimal.h"
#include "CelestialDiskMeshParameters.h"
#include "MoonDiskComputedState.h"
#include "MoonDiskParameters.h"
#include "MoonDisk.generated.h"

class UMaterial;
class UMaterialInstanceDynamic;
class UMaterialParameterCollection;
class UProceduralMeshComponent;

USTRUCT(BlueprintType)
struct DAYNIGHT_API FMoonDisk {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UProceduralMeshComponent* MeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterial* BaseMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* DynamicMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMoonDiskParameters Parameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMoonDiskComputedState CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCelestialDiskMeshParameters MeshParameters;
    
    FMoonDisk();
};

