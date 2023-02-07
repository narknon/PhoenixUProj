#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblAnimTransitionInOverriderer.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblAnimTransitionInOverriderer : public UObject {
    GENERATED_BODY()
public:
    UAblAnimTransitionInOverriderer();
};

