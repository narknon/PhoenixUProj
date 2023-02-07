#pragma once
#include "CoreMinimal.h"
#include "ScalarValueVelocity.h"
#include "AngularValueVelocity.generated.h"

USTRUCT(BlueprintType)
struct FAngularValueVelocity : public FScalarValueVelocity {
    GENERATED_BODY()
public:
    CAMERASTACK_API FAngularValueVelocity();
};

