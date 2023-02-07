#pragma once
#include "CoreMinimal.h"
#include "Enemy_PerceptionChoice.h"
#include "Companion_PerceptionChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UCompanion_PerceptionChoice : public UEnemy_PerceptionChoice {
    GENERATED_BODY()
public:
    UCompanion_PerceptionChoice();
};

