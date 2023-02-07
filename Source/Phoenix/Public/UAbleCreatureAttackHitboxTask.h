#pragma once
#include "CoreMinimal.h"
#include "ablAttackHitboxTask.h"
#include "UAbleCreatureAttackHitboxTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UUAbleCreatureAttackHitboxTask : public UablAttackHitboxTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FName> CreatureTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddForMountsOnly;
    
public:
    UUAbleCreatureAttackHitboxTask();
};

