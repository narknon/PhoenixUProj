#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RagdollState.h"
#include "RagdollBehaviorBase.generated.h"

UCLASS(Blueprintable)
class RAGDOLL_API URagdollBehaviorBase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRagdollState RequireStatesAlways;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRagdollState RequireStatesToEnter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRagdollState RequireStatesToMantain;
    
    URagdollBehaviorBase();
};

