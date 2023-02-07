#pragma once
#include "CoreMinimal.h"
#include "RagdollRecoveryAssistPlugin.h"
#include "RagdollRecoveryAssistPlugin_GuideToSafeRecovery.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, EditInlineNew)
class RAGDOLL_API URagdollRecoveryAssistPlugin_GuideToSafeRecovery : public URagdollRecoveryAssistPlugin {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* PushStrengthToTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PushCutoffDistance;
    
    URagdollRecoveryAssistPlugin_GuideToSafeRecovery();
};

