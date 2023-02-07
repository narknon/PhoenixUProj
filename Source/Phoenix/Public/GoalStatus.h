#pragma once
#include "CoreMinimal.h"
#include "EGoalStatusFlags.h"
#include "GoalStatus.generated.h"

USTRUCT(BlueprintType)
struct FGoalStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool GoalIsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SiteIsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StationIsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EGoalStatusFlags::Type> Status;
    
    PHOENIX_API FGoalStatus();
};

