#pragma once
#include "CoreMinimal.h"
#include "AblAnimNotify.h"
#include "EEnemy_AbilityEvent.h"
#include "AblEnemyAnimNotify.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class UAblEnemyAnimNotify : public UAblAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_AbilityEvent AbilityEvent;
    
    UAblEnemyAnimNotify();
};

