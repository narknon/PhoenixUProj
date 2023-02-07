#pragma once
#include "CoreMinimal.h"
#include "CurtainStageOptions.h"
#include "OnCurtainStageDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurtainStage, FCurtainStageOptions, CurtainStageOptions);

