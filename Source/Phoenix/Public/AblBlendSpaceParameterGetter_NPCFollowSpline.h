#pragma once
#include "CoreMinimal.h"
#include "AblSpeedCompensateBlendSpaceParameterGetter.h"
#include "AblBlendSpaceParameterGetter_NPCFollowSpline.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendSpaceParameterGetter_NPCFollowSpline : public UAblSpeedCompensateBlendSpaceParameterGetter {
    GENERATED_BODY()
public:
    UAblBlendSpaceParameterGetter_NPCFollowSpline();
};

