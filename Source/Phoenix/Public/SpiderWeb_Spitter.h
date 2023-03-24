#pragma once
#include "CoreMinimal.h"
#include "ETargetSpeedMode.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "SpiderWeb_Spitter.generated.h"

class AAble_Character;
class ABiped_Character;
class ACharacter;
class UActorComponent;
class UAmbulatory_MovementComponent;
class UBoxComponent;
class UCapsuleComponent;
class UMaterialInstanceDynamic;
class UObjectStateInfo;
class UPoseableMeshComponent;
class UPrimitiveComponent;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ASpiderWeb_Spitter : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRegen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RegenTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxWebLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAffectPawns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETargetSpeedMode::Type> CharSpeedMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WebLinearDamping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WebAngularDamping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWebPushback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PushbackMaxForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PushbackDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReactiveMaterials;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* StickyTrig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* PushTrig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPoseableMeshComponent* WebMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPoseableMeshComponent* WebMesh2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObjectStateInfo* WebObjectState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WebEndLoc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<UPrimitiveComponent*, UActorComponent*> WebbedCompMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AAble_Character*> WebbedRagdolls;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UPrimitiveComponent*, TEnumAsByte<ECollisionChannel>> ObjectTypeMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UPrimitiveComponent*, FName> CollisionPresetMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ACharacter*> NearbyCharacters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAmbulatory_MovementComponent*> CharMovementComps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ACharacter*> CharsToRemove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFrozen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBroken;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* InMatDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* OutMatDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* PhysicsTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SkeletalTargetBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickyTrigHalfHeight;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PushbackExponent;
    
public:
    ASpiderWeb_Spitter(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void WebThaw();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void WebRegened();
    
private:
    UFUNCTION(BlueprintCallable)
    void WebFreeze();
    
    UFUNCTION(BlueprintCallable)
    void WebDestroyed();
    
    UFUNCTION(BlueprintCallable)
    void UnDamp(UPrimitiveComponent* PrimComp);
    
    UFUNCTION(BlueprintCallable)
    void StartSkeletalMat(ABiped_Character* SkelActor);
    
    UFUNCTION(BlueprintCallable)
    void StartPhysicsMat(UPrimitiveComponent* HitComp);
    
    UFUNCTION(BlueprintCallable)
    void SkeletalMat();
    
    UFUNCTION(BlueprintCallable)
    FVector SetWebEnd(bool i_Retract, bool i_Lerp, float i_Alpha);
    
    UFUNCTION(BlueprintCallable)
    void SetMeshTick(bool i_Tick);
    
    UFUNCTION(BlueprintCallable)
    void SetAIBlocker(bool i_block);
    
    UFUNCTION(BlueprintCallable)
    void PushBack();
    
    UFUNCTION(BlueprintCallable)
    void PhysicsMat();
    
    UFUNCTION(BlueprintCallable)
    void PhysicsHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    void OnStickyOverlapEnd(AActor* OtherActor, UPrimitiveComponent* OtherComp);
    
    UFUNCTION(BlueprintCallable)
    void OnStickyOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp);
    
    UFUNCTION(BlueprintCallable)
    void OnPushOverlapEnd(AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnPushOverlapBegin(AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void InitOverlap();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CreatePhysicsConstraint(UPrimitiveComponent* PrimComp);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CreateBonePhysicsConstraint(USkeletalMeshComponent* skelComp, FName BoneName);
    
};

