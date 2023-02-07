#pragma once
#include "CoreMinimal.h"
#include "WorldObjectReference.h"
#include "WorldActorReference.generated.h"

USTRUCT(BlueprintType)
struct UTILITIESRUNTIME_API FWorldActorReference : public FWorldObjectReference {
    GENERATED_BODY()
public:
    FWorldActorReference();
};

