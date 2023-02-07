#pragma once
#include "CoreMinimal.h"
#include "RagdollState.generated.h"

class URagdollSensoryState;

USTRUCT(BlueprintType)
struct RAGDOLL_API FRagdollState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URagdollSensoryState*> RequiredAll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URagdollSensoryState*> RequiredAny;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URagdollSensoryState*> RequiredNone;
    
    FRagdollState();
};

