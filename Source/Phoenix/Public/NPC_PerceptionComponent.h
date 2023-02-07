#pragma once
#include "CoreMinimal.h"
#include "Game_PerceptionComponent.h"
#include "NPC_PerceptionComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UNPC_PerceptionComponent : public UGame_PerceptionComponent {
    GENERATED_BODY()
public:
    UNPC_PerceptionComponent();
};

