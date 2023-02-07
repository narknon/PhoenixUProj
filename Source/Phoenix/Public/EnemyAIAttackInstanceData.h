#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EnemyAIAttackInstanceData.generated.h"

class UEnemy_AttackExtraData;

UCLASS(Blueprintable)
class UEnemyAIAttackInstanceData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemy_AttackExtraData* ExtraData;
    
    UEnemyAIAttackInstanceData();
};

