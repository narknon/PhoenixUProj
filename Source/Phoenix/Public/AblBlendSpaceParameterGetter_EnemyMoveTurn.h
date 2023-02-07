#pragma once
#include "CoreMinimal.h"
#include "AblSpeedCompensateBlendSpaceParameterGetter.h"
#include "AblBlendSpaceParameterGetter_EnemyMoveTurn.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendSpaceParameterGetter_EnemyMoveTurn : public UAblSpeedCompensateBlendSpaceParameterGetter {
    GENERATED_BODY()
public:
    UAblBlendSpaceParameterGetter_EnemyMoveTurn();
};

