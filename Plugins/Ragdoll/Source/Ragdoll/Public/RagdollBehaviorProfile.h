#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RagdollBehaviorProfile.generated.h"

class URagdollBehavior;

UCLASS(Blueprintable)
class RAGDOLL_API URagdollBehaviorProfile : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URagdollBehavior*> Behaviors;
    
    URagdollBehaviorProfile();
};

