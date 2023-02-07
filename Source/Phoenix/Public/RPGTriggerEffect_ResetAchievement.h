#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_ResetAchievement.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_ResetAchievement : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AchievementID;
    
public:
    URPGTriggerEffect_ResetAchievement();
};

