#pragma once
#include "CoreMinimal.h"
#include "BTCustomAction.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/StaticMeshActor.h"
#include "VariantMapHandle.h"
#include "ESpiderTypeEnum.h"
#include "SpiderWeb_EggSack.generated.h"

class AActor;
class UEnemy_SpawnSpiders;
class UInteractionArchitectAsset;

UCLASS(Blueprintable)
class ASpiderWeb_EggSack : public AStaticMeshActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBroken;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFrozen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnFire;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ObjectDBID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LootChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpiderChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpiderTypeEnum SpiderType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseSpiderNum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpiderNumVariance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExplodeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExplosionDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExplosionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OnFireExplosionDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OnFireExplosionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AccioTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EObjectTypeQuery>> OverlapActorTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> IgnoreActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInteractionArchitectAsset*> ExplodeMunition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitResult BlankHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBTCustomAction StumbleAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVariantMapHandle ActionMapHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemy_SpawnSpiders* EnemySpiders;
    
public:
    ASpiderWeb_EggSack();
protected:
    UFUNCTION(BlueprintCallable)
    void StartAccioTimer(bool i_Start);
    
    UFUNCTION(BlueprintCallable)
    void SpawnSpiders();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SpawnLoot();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SpawnEnemySpiders();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SpawnDBObject();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnBreak(bool i_Explode);
    
    UFUNCTION(BlueprintCallable)
    void InitializeSack(float i_LootChance, float i_SpiderChance, ESpiderTypeEnum i_SpiderType, int32 i_SpiderBaseNum, int32 i_SpiderNumVariation, bool i_bObjectNotSpiders, const FString& i_ObjectDBID);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ExplodeSack();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AccioBreak();
    
};

