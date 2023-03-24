#pragma once
#include "CoreMinimal.h"
#include "WorldBaseHeightShape.h"
#include "WorldBaseHeightRect.generated.h"

UCLASS(Blueprintable)
class GLOBALLIGHTRIG_API AWorldBaseHeightRect : public AWorldBaseHeightShape {
    GENERATED_BODY()
public:
    AWorldBaseHeightRect(const FObjectInitializer& ObjectInitializer);
};

