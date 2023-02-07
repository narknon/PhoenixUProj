#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblBlendWeightMultiplierGetter.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblBlendWeightMultiplierGetter : public UObject {
    GENERATED_BODY()
public:
    UAblBlendWeightMultiplierGetter();
};

