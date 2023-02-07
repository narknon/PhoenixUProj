#pragma once
#include "CoreMinimal.h"
#include "OrientToComponent.h"
#include "PointAtComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPointAtComponent : public UOrientToComponent {
    GENERATED_BODY()
public:
    UPointAtComponent();
};

