#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESpiderTypeEnum.h"
#include "WorldObject.h"
#include "SpiderWeb_HangingBase.generated.h"

class ASpiderWeb_EggSack;
class UParticleSystem;
class UPhysicsConstraintComponent;
class UPoseableMeshComponent;
class USceneComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASpiderWeb_HangingBase : public AWorldObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CableLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LootChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ObjectDBID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnSpiders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpiderTypeEnum SpiderType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpiderChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseSpiderNum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpiderNumVariance;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* SnapParticle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtraCableLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CableLengthTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DescendoCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBroken;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* AnchorComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPoseableMeshComponent* PosableMeshComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhysicsConstraintComponent* PhysicsConstraintComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASpiderWeb_EggSack* SpawnedSack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* SackMeshComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* TargetComp;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WebEndLoc;
    
public:
    ASpiderWeb_HangingBase(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void WingardiumStart(bool i_Start);
    
    UFUNCTION(BlueprintCallable)
    void WebRetract();
    
    UFUNCTION(BlueprintCallable)
    void WakeTick(bool i_Wake);
    
    UFUNCTION(BlueprintCallable)
    void StartWebRetract();
    
    UFUNCTION(BlueprintCallable)
    void ScaleStart(bool i_Start, bool i_ScaleUp);
    
    UFUNCTION(BlueprintCallable)
    void EndWebRetract();
    
    UFUNCTION(BlueprintCallable)
    void DescendoHit();
    
    UFUNCTION(BlueprintCallable)
    void BreakConnection(bool i_Explode);
    
    UFUNCTION(BlueprintCallable)
    void AccioStart(bool i_Start, float i_Time);
    
    UFUNCTION(BlueprintCallable)
    void AccioPull();
    
};

