#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "Templates/SubclassOf.h"
#include "AIPerformTaskApparateToLocation.generated.h"

class UAblAbility;
class UScheduledEntity;

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskApparateToLocation : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ApparateInAblAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ApparateOutAblAbility;
    
    UAIPerformTaskApparateToLocation();
private:
    UFUNCTION(BlueprintCallable)
    void OnApparateOutCompleted(UScheduledEntity* InScheduledEntity, int32 ActivityTypeBits);
    
};

