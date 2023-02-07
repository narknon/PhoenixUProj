#pragma once
#include "CoreMinimal.h"
#include "RagdollState.h"
#include "RagdollGetupOptions.generated.h"

USTRUCT(BlueprintType)
struct RAGDOLL_API FRagdollGetupOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRagdollState RequiredState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetGetupProfile;
    
    FRagdollGetupOptions();
};

