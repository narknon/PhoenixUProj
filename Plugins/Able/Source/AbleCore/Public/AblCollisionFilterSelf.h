#pragma once
#include "CoreMinimal.h"
#include "AblCollisionFilter.h"
#include "AblCollisionFilterSelf.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblCollisionFilterSelf : public UAblCollisionFilter {
    GENERATED_BODY()
public:
    UAblCollisionFilterSelf();
};

