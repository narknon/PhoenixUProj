#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesLocalEvaluationDelegateDelegate.generated.h"

class ULerpVolumesLocalEvaluationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLerpVolumesLocalEvaluationDelegate, ULerpVolumesLocalEvaluationComponent*, LerpVolumesLocalEvaluationComponent);

