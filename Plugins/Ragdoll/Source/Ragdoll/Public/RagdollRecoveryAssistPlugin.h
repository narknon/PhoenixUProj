#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RagdollRecoveryAssistPlugin.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class RAGDOLL_API URagdollRecoveryAssistPlugin : public UObject {
    GENERATED_BODY()
public:
    URagdollRecoveryAssistPlugin();
};

