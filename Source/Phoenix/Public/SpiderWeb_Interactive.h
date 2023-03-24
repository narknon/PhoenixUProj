#pragma once
#include "CoreMinimal.h"
#include "ETargetSpeedMode.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "WorldObject.h"
#include "SpiderWeb_Interactive.generated.h"

class AAble_Character;
class AActor;
class ABiped_Character;
class ACharacter;
class UAmbulatory_MovementComponent;
class UMaterialInstanceDynamic;
class UObjectStateInfo;
class UPrimitiveComponent;
class USkeletalMeshComponent;
class USphereComponent;

UCLASS(Blueprintable)
class ASpiderWeb_Interactive : public AWorldObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETargetSpeedMode::Type> CharSpeedMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WebLinearDamping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WebAngularDamping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReactiveMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugBurnSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentageDisableCollision;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> WebbedComponents;
    
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
    TArray<AActor*> BurnActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFrozen;
    
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
    float BurnRate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* RootComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObjectStateInfo* WebObjectState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* BurnSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BurnDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BurnDistNeeded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector BurnOrigin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> IgnoreBurnActors;
    
public:
    ASpiderWeb_Interactive(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void WebThaw();
    
    UFUNCTION(BlueprintCallable)
    void WebFreeze();
    
    UFUNCTION(BlueprintCallable)
    void WebBurn(FVector burnLoc);
    
    UFUNCTION(BlueprintCallable)
    void WakeCompBody(UPrimitiveComponent* PrimComp);
    
    UFUNCTION(BlueprintCallable)
    void UnDamp(UPrimitiveComponent* PrimComp);
    
    UFUNCTION(BlueprintCallable)
    void StartSkeletalMat(ABiped_Character* SkelActor);
    
    UFUNCTION(BlueprintCallable)
    void StartPhysicsMat(UPrimitiveComponent* HitComp);
    
    UFUNCTION(BlueprintCallable)
    void SkeletalMat();
    
    UFUNCTION(BlueprintCallable)
    void PhysicsMat();
    
    UFUNCTION(BlueprintCallable)
    void PhysicsHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    void OnWebOverlapEnd(AActor* OtherActor, UPrimitiveComponent* OtherComp);
    
    UFUNCTION(BlueprintCallable)
    void OnWebOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp);
    
    UFUNCTION(BlueprintCallable)
    void OnFullyCharred(bool bCharred);
    
    UFUNCTION(BlueprintCallable)
    void OnFireOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnFireOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void InitFireOverlap();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetRelativeTransform(UPrimitiveComponent* PrimComp, FVector FireLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCollisionScale();
    
    UFUNCTION(BlueprintCallable)
    void DestroyWeb();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CreatePhysicsConstraint(UPrimitiveComponent* PrimComp);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CreateBonePhysicsConstraint(USkeletalMeshComponent* skelComp, FName BoneName);
    
};

