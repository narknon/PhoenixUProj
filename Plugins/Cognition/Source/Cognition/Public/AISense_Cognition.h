#pragma once
#include "CoreMinimal.h"
#include "Perception/AISense.h"
#include "AISense_Cognition.generated.h"

UCLASS(Abstract, Blueprintable)
class COGNITION_API UAISense_Cognition : public UAISense {
    GENERATED_BODY()
public:
    UAISense_Cognition();
};

