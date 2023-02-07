#pragma once
#include "CoreMinimal.h"
#include "BaseTagCommand.h"
#include "ETrafficFlow.h"
#include "BranchTagCommand.generated.h"

USTRUCT(BlueprintType)
struct AIPATHSCHEDULER_API FBranchTagCommand : public FBaseTagCommand {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 UUID_BranchTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FromPathPointIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ToPathPointIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Probability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETrafficFlow ForwardToBranchDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETrafficFlow BackwardToBranchDirection;
    
    FBranchTagCommand();
};

