#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblBlendSpaceParameterGetter.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblBlendSpaceParameterGetter : public UObject {
    GENERATED_BODY()
public:
    UAblBlendSpaceParameterGetter();
};

