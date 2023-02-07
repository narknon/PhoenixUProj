#pragma once
#include "CoreMinimal.h"
#include "RPGCondition.h"
#include "RPGCondition_PlayerOrCompanionInCombat.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGCondition_PlayerOrCompanionInCombat : public URPGCondition {
    GENERATED_BODY()
public:
    URPGCondition_PlayerOrCompanionInCombat();
};

