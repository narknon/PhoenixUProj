#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblAbilityNode.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblAbilityNode : public UObject {
    GENERATED_BODY()
public:
    UAblAbilityNode();
};

