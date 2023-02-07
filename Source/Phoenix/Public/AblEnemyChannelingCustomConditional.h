#pragma once
#include "CoreMinimal.h"
#include "AblChannelingBase.h"
#include "Templates/SubclassOf.h"
#include "AblEnemyChannelingCustomConditional.generated.h"

class UAblAbility;

UCLASS(Blueprintable, EditInlineNew)
class UAblEnemyChannelingCustomConditional : public UAblChannelingBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> BranchAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBreakChannelingNearInstigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NearRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> BreakBranchAbility;
    
public:
    UAblEnemyChannelingCustomConditional();
};

