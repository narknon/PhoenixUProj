#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "EEnemy_WeaponReleaseType.h"
#include "SpawnStoredWeaponStr.h"
#include "Templates/SubclassOf.h"
#include "Enemy_WeaponComponent.generated.h"

class AActor;
class AEnemyAIWeapon;
class UDataTable;
class UEnemyAIAttackData;
class UEnemyAIComponent;
class UEnemy_AttackComponent;
class UInteractionArchitectAsset;
class UNPC_Component;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemy_WeaponComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActiveSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SecondaryActiveSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanStoreActiveWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* WeaponSocketTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnEnable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AEnemyAIWeapon>> SpawnWeaponDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpawnStoredWeaponStr> SpawnStoredWeaponDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AEnemyAIWeapon>> RespawnWeaponDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AEnemyAIWeapon>> ShieldWeaponDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AEnemyAIWeapon>> DeathWeaponDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DeathSpawnMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DeathSpawnMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AEnemyAIWeapon>> DisarmWeaponDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DisarmSpawnMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DisarmSpawnMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bVulnerableWhileDisarmed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemy_AttackComponent* AttackComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNPC_Component* NPCComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyAIComponent* EnemyComp;
    
    UEnemy_WeaponComponent();
    UFUNCTION(BlueprintCallable)
    void ThrowWeapon();
    
    UFUNCTION(BlueprintCallable)
    bool StoreWeapon(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    AEnemyAIWeapon* SpawnWeapon(TSubclassOf<AEnemyAIWeapon> SpawnWeaponClass);
    
    UFUNCTION(BlueprintCallable)
    void SetWeaponToRecover(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void SetWeaponToAcquire(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void SetWeapon(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnEnable(bool Flag);
    
    UFUNCTION(BlueprintCallable)
    void SetShieldToAcquire(AEnemyAIWeapon* InShieldPtr);
    
    UFUNCTION(BlueprintCallable)
    void SetShieldSpellDeflectionIfEquipped(bool bShouldDeflect);
    
    UFUNCTION(BlueprintCallable)
    void SetShield(AEnemyAIWeapon* InShieldPtr);
    
    UFUNCTION(BlueprintCallable)
    void SetRecoverWeapon(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void SetRecoverSecondaryWeapon(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void RespawnWeapon();
    
    UFUNCTION(BlueprintCallable)
    void RemoveStoredWeapon(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseWeaponType(AEnemyAIWeapon* InWeaponPtr, EEnemy_WeaponReleaseType InReleaseType);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseWeapon(AEnemyAIWeapon* InWeaponPtr, bool bForceDestroy, bool bSetDropVel, bool bIsThrown, bool bForceDrop);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseShield(AEnemyAIWeapon* InShieldPtr, bool bSetDropVel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWeaponStored(AEnemyAIWeapon* InWeaponPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRequiredWeaponStored(const UEnemyAIAttackData* AttackPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRequiredWeaponActive(const UEnemyAIAttackData* AttackPtr) const;
    
    UFUNCTION(BlueprintCallable)
    void HideActiveWeapon(bool bHide);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasWeaponToRecover() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasWeaponToAcquire() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasStoredWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasShield() const;
    
    UFUNCTION(BlueprintCallable)
    AEnemyAIWeapon* GetWeaponToRecover();
    
    UFUNCTION(BlueprintCallable)
    AEnemyAIWeapon* GetWeaponToAcquire();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWeaponRequiredPercent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEnemyAIWeapon* GetWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEnemyAIWeapon* GetTransientWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<AEnemyAIWeapon> GetStoreWeaponClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEnemyAIWeapon* GetStoredWeapon(const TArray<TSubclassOf<AEnemyAIWeapon>>& WeaponClassList, bool bGetFirstMatch) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<AEnemyAIWeapon> GetSpawnWeaponClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<AEnemyAIWeapon> GetShieldWeaponClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<AEnemyAIWeapon> GetRespawnWeaponClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEnemyAIWeapon* GetRecoverWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEnemyAIWeapon* GetRecoverSecondaryWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTagContainer GetEnemyWeaponTagContainer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInteractionArchitectAsset* GetEnemyWeaponDataAsset() const;
    
    UFUNCTION(BlueprintCallable)
    void FireWeaponAOE1(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool FindAvailableStoredWeaponSocket(AEnemyAIWeapon* InWeaponPtr, FName& OutSocketName, FVector& OutSocketTranslationOffset, FRotator& OutSocketRotationOffset) const;
    
    UFUNCTION(BlueprintCallable)
    void EnableWeaponCollision();
    
    UFUNCTION(BlueprintCallable)
    void EnableShieldCollision();
    
    UFUNCTION(BlueprintCallable)
    void EnableProvidedWeaponCollision(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    AActor* DisarmWeaponToRecover(float ScaleForce);
    
    UFUNCTION(BlueprintCallable)
    AActor* DisarmWeapon(float ScaleForce);
    
    UFUNCTION(BlueprintCallable)
    AActor* DisarmShield(float ScaleForce);
    
    UFUNCTION(BlueprintCallable)
    void DisableWeaponCollision();
    
    UFUNCTION(BlueprintCallable)
    void DisableShieldCollision();
    
    UFUNCTION(BlueprintCallable)
    void DisableProvidedWeaponCollision(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void DeathSpawnWeapon();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanStoreWeapon(AEnemyAIWeapon* InWeaponPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPerceiveThisWeapon(AEnemyAIWeapon* InWeaponPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAnyStoredWeaponBeThrown() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void AllWeaponsLifetimeToZero() const;
    
    UFUNCTION(BlueprintCallable)
    void ActivateRequiredWeapon();
    
    UFUNCTION(BlueprintCallable)
    void AcquireWeapon(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void AcquireShield(AEnemyAIWeapon* InShieldPtr);
    
};

