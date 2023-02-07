#pragma once
#include "CoreMinimal.h"
#include "NPC_MobilitySpeedChoice.h"
#include "Wolf_FollowOwnerSpeedChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWolf_FollowOwnerSpeedChoice : public UNPC_MobilitySpeedChoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceFromOwnerTrotThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateTimeDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateTimeDeltaRandomNudge;
    
    UWolf_FollowOwnerSpeedChoice();
};

