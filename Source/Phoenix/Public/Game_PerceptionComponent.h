#pragma once
#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "Game_PerceptionComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UGame_PerceptionComponent : public UAIPerceptionComponent {
    GENERATED_BODY()
public:
    UGame_PerceptionComponent();
};

