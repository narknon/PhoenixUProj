#pragma once
#include "CoreMinimal.h"
#include "ExplosiveBarrel.h"
#include "WaterBarrel.generated.h"

UCLASS(Blueprintable)
class AWaterBarrel : public AExplosiveBarrel {
    GENERATED_BODY()
public:
    AWaterBarrel(const FObjectInitializer& ObjectInitializer);
};

