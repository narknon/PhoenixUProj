#pragma once
#include "CoreMinimal.h"
#include "AblCollisionFilter.h"
#include "AblCollisionFilterOwner.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblCollisionFilterOwner : public UAblCollisionFilter {
    GENERATED_BODY()
public:
    UAblCollisionFilterOwner();
};

