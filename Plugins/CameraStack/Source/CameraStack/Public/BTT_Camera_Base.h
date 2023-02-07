#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Camera_Base.generated.h"

UCLASS(Blueprintable)
class CAMERASTACK_API UBTT_Camera_Base : public UBTTaskNode {
    GENERATED_BODY()
public:
    UBTT_Camera_Base();
};

