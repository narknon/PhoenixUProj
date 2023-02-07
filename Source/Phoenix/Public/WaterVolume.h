#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "WaterVolumeBase.h"
#include "WaterVolume.generated.h"

class ULakeAudioComponent;
class USceneComponent;
class UStaticMesh;
class UWaterTileMeshComponent;

UCLASS(Blueprintable)
class PHOENIX_API AWaterVolume : public AWaterVolumeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* RootComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWaterTileMeshComponent* WaterTileMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULakeAudioComponent* LakeAudioComponent;
    
    AWaterVolume();
    UFUNCTION(BlueprintCallable)
    void SetupWater(FBoxSphereBounds i_Bounds, UStaticMesh* i_DeepCollision, const FVector& i_DeepLocation, UStaticMesh* i_ShallowCollision, const FVector& i_ShallowLocation);
    
    UFUNCTION(BlueprintCallable)
    void RecalculateDepth();
    
};

