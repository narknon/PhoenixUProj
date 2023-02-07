#pragma once
#include "CoreMinimal.h"
#include "RPGCondition.h"
#include "RPGCondition_PlayerInCombat.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGCondition_PlayerInCombat : public URPGCondition {
    GENERATED_BODY()
public:
    URPGCondition_PlayerInCombat();
};

