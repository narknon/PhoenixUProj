#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "WaterMeshAccelerationStructure.h"
#include "WaterTileMeshComponent.generated.h"

class UInstancedStaticMeshComponent;
class UMaterialInstanceDynamic;
class URuntimeHierarchicalInstancedStaticMeshComponent;
class UStaticMesh;
class UTexture;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FLOW_API UWaterTileMeshComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SubtileMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector4 LakeRelativeOffsetAndExtents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LakeSize;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* TextureDirAndDistToCoast;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* TextureFlowAndWaterDepth;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWaterMeshAccelerationStructure AccelerationStructure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<URuntimeHierarchicalInstancedStaticMeshComponent*> HierarchicalInstancedTilesComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UInstancedStaticMeshComponent*> InstancedTilesComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> WaterMaterialInstances;
    
public:
    UWaterTileMeshComponent();
    UFUNCTION(BlueprintCallable)
    void RebuildAccelerationStructure();
    
};

