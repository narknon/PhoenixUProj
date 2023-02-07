#pragma once
#include "CoreMinimal.h"
#include "EFKIKBranchType.h"
#include "KIKBone.generated.h"

USTRUCT(BlueprintType)
struct FKIKBone {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FKBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IKBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFKIKBranchType> FKIKBranch;
    
    ABLECORE_API FKIKBone();
};

