#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblCollisionFilter.generated.h"

UCLASS(Abstract, Blueprintable)
class ABLECORE_API UAblCollisionFilter : public UObject {
    GENERATED_BODY()
public:
    UAblCollisionFilter();
};

