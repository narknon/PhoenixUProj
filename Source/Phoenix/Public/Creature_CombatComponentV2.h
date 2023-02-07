#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OdcPathSpec.h"
#include "CreatureCombatAttackImpactData.h"
#include "CreatureCombatDataWrapper.h"
#include "ECreatureAIState.h"
#include "Creature_CombatComponentV2.generated.h"

class UCreatureCombatProgressionData;
class UCreature_AIComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UCreature_CombatComponentV2 : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreatureCombatProgressionData* ProgressionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCreatureCombatAttackImpactData> AttackImpactDataArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCreatureCombatDataWrapper> CombatDataArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcPathSpec AttackExecutionPathSpec;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStayInCombatDuringCinematic;
    
    UCreature_CombatComponentV2();
private:
    UFUNCTION(BlueprintCallable)
    void OnCreatureAIStateChanged(UCreature_AIComponent* AIComponent, ECreatureAIState PrevAIState);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    int32 GetCurrentCombatStageIndex() const;
    
};

