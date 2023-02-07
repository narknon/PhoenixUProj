#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RagdollSensoryBehavior.h"
#include "RagdollSensoryCollision.h"
#include "RagdollSensoryRange.h"
#include "RagdollSensoryStatus.h"
#include "RagdollState.h"
#include "RagdollSensoryState.generated.h"

UCLASS(Blueprintable)
class RAGDOLL_API URagdollSensoryState : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRagdollSensoryRange> SensoryRangeMatches;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRagdollSensoryStatus> SensoryStatusMatches;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRagdollSensoryBehavior> SensoryBehaviorsMatches;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRagdollSensoryCollision> SensoryCollisionMatches;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRagdollState AndRequire;
    
    URagdollSensoryState();
};

