#pragma once
#include "CoreMinimal.h"
#include "ETargetSpeedMode.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "MultiFX2Handle.h"
#include "EWaterVfx.h"
#include "WaterVolumeBase.generated.h"

class ACharacter;
class ARiverVolume;
class AWaterVolumeBase;
class UAmbulatory_MovementComponent;
class UBoxComponent;
class UObjectStateInfo;
class UPhoenixPhysicalMaterial;
class UPrimitiveComponent;
class URagdollControlComponent;
class UStaticMeshComponent;
class UWaterInteractionComponent;

UCLASS(Blueprintable)
class PHOENIX_API AWaterVolumeBase : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* WaterBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* DeepCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ShallowCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableFunctionality;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhysicsVolumeFluidFriction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhoenixPhysicalMaterial* WaterPhysMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhoenixPhysicalMaterial* PuddlePhysMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> OverlapIgnores;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> WaterIgnoreActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AWaterVolumeBase*> OverlappingWaterVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARiverVolume*> OverlappingRiverVolumes;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaterHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinWaterHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForcePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> BuoyancyActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> BuoyancyForces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> BuoyancyMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> BuoyancyMasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<bool> MeshInWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> MeshUnderwater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URagdollControlComponent*> ObjectRagdollComps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ToBeRemoved;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ACharacter*> OverlappingCharacters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAmbulatory_MovementComponent*> CharacterMovementComps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<ETargetSpeedMode::Type>> CharSpeedModes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URagdollControlComponent*> CharacterRagdollComps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWaterInteractionComponent*> CharacterWICs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<bool> CharInWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ACharacter*> RemoveChars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ACharacter*> TransferringChars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ACharacter*> KillInWaterChars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWaterInteractionComponent*> KIW_WICs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<bool> KIWInWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ACharacter*> RemoveKIWChars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> FloatVFXActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> FloatVFXTransfers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> IgnoreEnterWaterVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMultiFX2Handle> FloatVFXHandles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<AActor*, float> RecentExitMap;
    
public:
    AWaterVolumeBase(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void UnDamp(UPrimitiveComponent* Mesh, UObjectStateInfo* ObjectState);
    
    UFUNCTION(BlueprintCallable)
    void SplashVFX(bool i_Char, EWaterVfx i_vfx, AActor* curActor, UPrimitiveComponent* PrimComp, float waterZ, FVector waterNorm, bool bShallow);
    
    UFUNCTION(BlueprintCallable)
    void SetupObject(AActor* Actor, UPrimitiveComponent* Mesh, UObjectStateInfo* ObjectState, bool bShouldFloat, bool bSkipIgnore, bool bOverlappingLakeSphere, URagdollControlComponent* RagdollComp);
    
    UFUNCTION(BlueprintCallable)
    void SetupCharacter(ACharacter* Character, UObjectStateInfo* ObjectState, URagdollControlComponent* RagdollComp, bool bSkipIgnore, bool bOverlappingLakeSphere);
    
    UFUNCTION(BlueprintCallable)
    void RemoveVFX(EWaterVfx i_vfx, AActor* curActor);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveActors();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnRagdollRecoveredInWater(URagdollControlComponent* RagdollControlComponent);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    FBoxSphereBounds GetBounds(UPrimitiveComponent* Mesh);
    
public:
    UFUNCTION(BlueprintCallable)
    void ExplosionVFX(AActor* curActor, UPrimitiveComponent* PrimComp, FVector Location, bool inWater, float InForce, float Radius, float Falloff);
    
protected:
    UFUNCTION(BlueprintCallable)
    void Damp(UPrimitiveComponent* Mesh, UObjectStateInfo* ObjectState);
    
    UFUNCTION(BlueprintCallable)
    void CalcForce(AActor* Actor, UPrimitiveComponent* Mesh, float i_Mass, bool bEmplace, URagdollControlComponent* RagdollComp);
    
};

