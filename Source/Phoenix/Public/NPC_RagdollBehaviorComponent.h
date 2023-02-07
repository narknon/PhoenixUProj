#pragma once
#include "CoreMinimal.h"
#include "RagdollBehaviorComponent.h"
#include "NPC_RagdollBehaviorComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UNPC_RagdollBehaviorComponent : public URagdollBehaviorComponent {
    GENERATED_BODY()
public:
    UNPC_RagdollBehaviorComponent();
};

