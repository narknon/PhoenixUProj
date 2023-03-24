#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/KismetSystemLibrary.h"
#include "WaterVolumeBase.h"
#include "RiverVolume.generated.h"

class AActor;
class UPrimitiveComponent;
class USphereComponent;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class PHOENIX_API ARiverVolume : public AWaterVolumeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* RiverMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RiverFlowSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugFlowView;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* LakeSphereIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* LakeSphereOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FVector, FVector2D> RiverFlowPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector RiverAveDir;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> LakeActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> RemoveLakeActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EDrawDebugTrace::Type> DebugFlowView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFlowInLake;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFlowOutLake;
    
public:
    ARiverVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetupRiver(FTransform i_RiverTransform, FVector i_RiverAveDir, TMap<FVector, FVector2D> i_RiverFlowPoints, FBoxSphereBounds i_WaterBoxInfo, float i_VolumeZRotation, UStaticMesh* i_RiverMesh, UStaticMesh* i_DeepCollision, UStaticMesh* i_ShallowCollision, bool i_bFlowInLake, bool i_bFlowOutLake);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnLakeSphereOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnActorOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetForceVector(UPrimitiveComponent* PrimComp, bool bUseDist);
    
};

