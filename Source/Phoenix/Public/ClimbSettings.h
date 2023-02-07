#pragma once
#include "CoreMinimal.h"
#include "ClimbRangeSet.h"
#include "Templates/SubclassOf.h"
#include "ClimbSettings.generated.h"

class UAblAbility;

USTRUCT(BlueprintType)
struct FClimbSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceReachingClimbLinkEndLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSnapRotationBeforeClimb;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ClimbAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> JumpToClimbAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> SwimClimbAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FClimbRangeSet> ClimbVariations;
    
    PHOENIX_API FClimbSettings();
};

