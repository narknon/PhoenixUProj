#pragma once
#include "CoreMinimal.h"
#include "NPC_MobilitySpeedChoice.h"
#include "Wolf_CloseDistanceSpeedChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWolf_CloseDistanceSpeedChoice : public UNPC_MobilitySpeedChoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CloseDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MiddleDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CloseSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MiddleSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FarSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateTime;
    
    UWolf_CloseDistanceSpeedChoice();
};

