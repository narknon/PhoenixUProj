#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NPC_MobilityAbilityData.h"
#include "NPC_MobilityAnimBlendSpaceData.h"
#include "NPC_MobilityAnimSpeedData.h"
#include "Templates/SubclassOf.h"
#include "NPC_MobilityAnimData.generated.h"

class UAblAbility;

USTRUCT(BlueprintType)
struct FNPC_MobilityAnimData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> IdleAbilityPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> MoveAbilityPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MoveTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_MobilityAbilityData MoveStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_MobilityAbilityData MoveStop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_MobilityAbilityData MovePivot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNPC_MobilityAnimSpeedData> AnimSpeedData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNPC_MobilityAnimBlendSpaceData> BlendSpaceData;
    
    PHOENIX_API FNPC_MobilityAnimData();
};

