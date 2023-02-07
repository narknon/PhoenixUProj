#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "EPerformTaskCombatMode.h"
#include "AIPerformTaskCombatMode.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskCombatMode : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NewTeamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AudioSubtypeID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartCombatMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTaskCombatMode CombatMode;
    
    UAIPerformTaskCombatMode();
protected:
    UFUNCTION(BlueprintCallable)
    void FinishAfterDuration();
    
};

