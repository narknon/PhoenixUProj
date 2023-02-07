#pragma once
#include "CoreMinimal.h"
#include "RagdollBodyAttachment.generated.h"

USTRUCT(BlueprintType)
struct FRagdollBodyAttachment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AttachBodyNames;
    
    RAGDOLL_API FRagdollBodyAttachment();
};

