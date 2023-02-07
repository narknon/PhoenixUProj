#pragma once
#include "CoreMinimal.h"
#include "RagdollBehaviorBase.h"
#include "RagdollRecoveryAssistBehavior.generated.h"

class URagdollRecoveryAssistPlugin;

UCLASS(Blueprintable)
class RAGDOLL_API URagdollRecoveryAssistBehavior : public URagdollBehaviorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URagdollRecoveryAssistPlugin* RunAssistPlugin;
    
    URagdollRecoveryAssistBehavior();
};

