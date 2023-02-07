#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "NPC_BTComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UNPC_BTComponent : public UBehaviorTreeComponent {
    GENERATED_BODY()
public:
    UNPC_BTComponent();
};

