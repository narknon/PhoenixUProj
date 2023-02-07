#pragma once
#include "CoreMinimal.h"
#include "NavigationSystem.h"
#include "PhoenixNavigationSystem.generated.h"

UCLASS(Blueprintable, NonTransient)
class UPhoenixNavigationSystem : public UNavigationSystemV1 {
    GENERATED_BODY()
public:
    UPhoenixNavigationSystem();
};

