#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EAccessibilityAudioCueEventType.h"
#include "AblPostAccessibilityAudioCueTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblPostAccessibilityAudioCueTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAccessibilityAudioCueEventType> AudioCueEventType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOneShot;
    
    UAblPostAccessibilityAudioCueTask();
};

