#pragma once
#include "CoreMinimal.h"
#include "WorldBaseHeightBase.h"
#include "WorldBaseHeightInfinitePlane.generated.h"

UCLASS(Blueprintable)
class GLOBALLIGHTRIG_API AWorldBaseHeightInfinitePlane : public AWorldBaseHeightBase {
    GENERATED_BODY()
public:
    AWorldBaseHeightInfinitePlane(const FObjectInitializer& ObjectInitializer);
};

