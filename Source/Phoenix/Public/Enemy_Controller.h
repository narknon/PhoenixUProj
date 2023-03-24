#pragma once
#include "CoreMinimal.h"
#include "NPC_Controller.h"
#include "Enemy_Controller.generated.h"

UCLASS(Blueprintable)
class AEnemy_Controller : public ANPC_Controller {
    GENERATED_BODY()
public:
    AEnemy_Controller(const FObjectInitializer& ObjectInitializer);
};

