#pragma once
#include "CoreMinimal.h"
#include "AblBlendSpaceParameterGetter.h"
#include "AblSpeedCompensateBlendSpaceParameterGetter.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblSpeedCompensateBlendSpaceParameterGetter : public UAblBlendSpaceParameterGetter {
    GENERATED_BODY()
public:
    UAblSpeedCompensateBlendSpaceParameterGetter();
};

