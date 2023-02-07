#pragma once
#include "CoreMinimal.h"
#include "AblBlendSpaceParameterGetter_MoveStrafe.h"
#include "AblBlendSpaceParameterGetter_StrafePivot.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendSpaceParameterGetter_StrafePivot : public UAblBlendSpaceParameterGetter_MoveStrafe {
    GENERATED_BODY()
public:
    UAblBlendSpaceParameterGetter_StrafePivot();
};

