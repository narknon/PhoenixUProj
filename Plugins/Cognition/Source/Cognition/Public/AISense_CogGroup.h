#pragma once
#include "CoreMinimal.h"
#include "AISense_Cognition.h"
#include "AISense_CogGroup.generated.h"

UCLASS(Abstract, Blueprintable)
class COGNITION_API UAISense_CogGroup : public UAISense_Cognition {
    GENERATED_BODY()
public:
    UAISense_CogGroup();
};

