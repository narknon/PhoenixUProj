#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "AblAnimationTagChooser_EnemyCounterAttack.generated.h"

class AEnemyAIWeapon;

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_EnemyCounterAttack : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer CounterTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AEnemyAIWeapon>> RequiredList;
    
    UAblAnimationTagChooser_EnemyCounterAttack();
};

