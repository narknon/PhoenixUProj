#pragma once
#include "CoreMinimal.h"
#include "AkAcousticTextureSetComponent.h"
#include "AkGeometryData.h"
#include "AkGeometrySurfaceOverride.h"
#include "AkMeshType.h"
#include "AkGeometryComponent.generated.h"

class AActor;
class UMaterialInterface;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class AKAUDIO_API UAkGeometryComponent : public UAkAcousticTextureSetComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AkMeshType MeshType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LOD;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeldingThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UMaterialInterface*, FAkGeometrySurfaceOverride> StaticMeshSurfaceOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAkGeometrySurfaceOverride CollisionMeshSurfaceOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bEnableDiffraction: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bEnableDiffractionOnBoundaryEdges: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* AssociatedRoom;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAkGeometryData GeometryData;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, double> SurfaceAreas;
    
public:
    UAkGeometryComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateGeometry();
    
    UFUNCTION(BlueprintCallable)
    void SendGeometry();
    
    UFUNCTION(BlueprintCallable)
    void RemoveGeometry();
    
    UFUNCTION(BlueprintCallable)
    void ConvertMesh();
    
};

