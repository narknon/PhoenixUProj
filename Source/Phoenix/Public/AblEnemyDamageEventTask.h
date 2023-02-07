#pragma once
#include "CoreMinimal.h"
#include "AblDamageEventTask.h"
#include "AblEnemyDamageEventTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblEnemyDamageEventTask : public UAblDamageEventTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDamageSystem;
    
public:
    UAblEnemyDamageEventTask();
};

