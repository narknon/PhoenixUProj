#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BTT_MoveToWithRadius.generated.h"

UCLASS(Blueprintable)
class UBTT_MoveToWithRadius : public UBTTask_MoveTo {
    GENERATED_BODY()
public:
    UBTT_MoveToWithRadius();
};

