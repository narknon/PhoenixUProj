#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "WaterVolumeBase.h"
#include "DungeonWaterVolume.generated.h"

class UMaterialInstance;
class USceneComponent;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class PHOENIX_API ADungeonWaterVolume : public AWaterVolumeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* RootComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* SurfacePlane;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShallowWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstance* WaterMaterial;
    
    ADungeonWaterVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetupWater(FBoxSphereBounds i_Bounds, UStaticMesh* i_SurfaceMesh, const FVector& i_SurfaceLocation, UStaticMesh* i_DeepCollision, const FVector& i_DeepLocation, UStaticMesh* i_ShallowCollision, const FVector& i_ShallowLocation);
    
    UFUNCTION(BlueprintCallable)
    void FinalizeSetup();
    
};

