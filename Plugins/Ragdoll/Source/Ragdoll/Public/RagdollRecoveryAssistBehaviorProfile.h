#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RagdollRecoveryAssistBehaviorProfile.generated.h"

class URagdollRecoveryAssistBehavior;

UCLASS(Blueprintable)
class RAGDOLL_API URagdollRecoveryAssistBehaviorProfile : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URagdollRecoveryAssistBehavior*> Behaviors;
    
    URagdollRecoveryAssistBehaviorProfile();
};

