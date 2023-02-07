#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "EnemyAIChosenAttackData.h"
#include "Enemy_SpellOverrides.h"
#include "Enemy_UnblockableData.h"
#include "Enemy_AttackComponent.generated.h"

class UBehaviorTree;
class UCurveFloat;
class UEnemyAIAttackData;
class UEnemyAIAttackInstanceData;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemy_AttackComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UEnemyAIAttackData*> AttackList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UEnemyAIAttackData*> CounterAttackList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UEnemyAIAttackData*> SplitAttackList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemy_SpellOverrides> OverrideSpellList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* ChooseAttackBehaviorTree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DungeonDistanceScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DungeonDistanceRangeScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HistoryWeightScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistToRangeCurveWeightScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponSeekDistToTargetCurveWeightScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* HistoryRatioCurveWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* DistToRangeCurveWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* WeaponSeekDistToTargetCurveWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ChooseAttackTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UEnemyAIAttackData*, UEnemyAIAttackInstanceData*> AttackInstanceDataMap;
    
    UEnemy_AttackComponent();
    UFUNCTION(BlueprintCallable)
    void RemoveSelectionTags(const FGameplayTagContainer& InTags);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSelectionTag(const FGameplayTag& InTag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAttackAllowed(UEnemyAIAttackData* AttackPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasSelectionTag(const FGameplayTag& InTag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasChosenAttack() const;
    
    UFUNCTION(BlueprintCallable)
    FEnemyAIChosenAttackData GetChosenAttackData();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FEnemy_UnblockableData GetAttackUnblockableData(UEnemyAIAttackData* attackDataPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UEnemyAIAttackData* GetAttackData() const;
    
    UFUNCTION(BlueprintCallable)
    void ClearSelectionTags();
    
    UFUNCTION(BlueprintCallable)
    void AddSelectionTags(const FGameplayTagContainer& InTags);
    
    UFUNCTION(BlueprintCallable)
    void AddSelectionTag(const FGameplayTag& InTag);
    
};

