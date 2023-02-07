#pragma once
#include "CoreMinimal.h"
#include "NPC_MobilitySpeedChoice.h"
#include "Wolf_DistanceSpeedChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWolf_DistanceSpeedChoice : public UNPC_MobilitySpeedChoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceFromTargetTrotThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceFromPathGoalTrotThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceFromPathGoalToTargetTrotThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateTimeDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateTimeDeltaRandomNudge;
    
    UWolf_DistanceSpeedChoice();
};

