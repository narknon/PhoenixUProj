#pragma once
#include "CoreMinimal.h"
#include "AblSpeedCompensateBlendSpaceParameterGetter.h"
#include "AblBlendSpaceParameterGetter_EnemyMove.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendSpaceParameterGetter_EnemyMove : public UAblSpeedCompensateBlendSpaceParameterGetter {
    GENERATED_BODY()
public:
    UAblBlendSpaceParameterGetter_EnemyMove();
};

