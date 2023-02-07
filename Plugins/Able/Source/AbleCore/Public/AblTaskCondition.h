#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblTaskCondition.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblTaskCondition : public UObject {
    GENERATED_BODY()
public:
    UAblTaskCondition();
};

