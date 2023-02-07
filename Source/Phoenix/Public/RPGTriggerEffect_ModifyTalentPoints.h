#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_ModifyTalentPoints.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_ModifyTalentPoints : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TalentPointModification;
    
    URPGTriggerEffect_ModifyTalentPoints();
};

