#pragma once
#include "CoreMinimal.h"
#include "AblAbility.h"
#include "EAblNpcReactChannelType.h"
#include "AblReactionAbility.generated.h"

class UAblAbilityContext;
class UAblReactionData;

UCLASS(Blueprintable)
class ABLECORE_API UAblReactionAbility : public UAblAbility {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AbleAbilityChannelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblNpcReactChannelType ChannelType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerInstigatorTicketTimeIncrease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddDeadTagIfDead;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWarmUpRagdollPhysics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBranchToRagdollInWater;
    
public:
    UAblReactionAbility();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAblReactionData* GetReactionData(const UAblAbilityContext* Context) const;
    
};

