#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "EPerformTaskSetting.h"
#include "PerformTaskSetTempAnimationArchitectAsset.generated.h"

class UAnimationArchitectAsset;

UCLASS(Blueprintable, EditInlineNew)
class UPerformTaskSetTempAnimationArchitectAsset : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationArchitectAsset* TriggerAnimationArchitectAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTaskSetting CurrentTaskSetting;
    
    UPerformTaskSetTempAnimationArchitectAsset();
};

