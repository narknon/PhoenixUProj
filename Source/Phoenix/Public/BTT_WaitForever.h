#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_WaitForever.generated.h"

UCLASS(Blueprintable)
class UBTT_WaitForever : public UBTTaskNode {
    GENERATED_BODY()
public:
    UBTT_WaitForever();
};

