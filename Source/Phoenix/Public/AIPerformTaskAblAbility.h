#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "Templates/SubclassOf.h"
#include "AIPerformTaskAblAbility.generated.h"

class UAblAbility;

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskAblAbility : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PartialBodyAbilityPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AbilityChannelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayPartialBodyAnimation;
    
    UAIPerformTaskAblAbility();
};

