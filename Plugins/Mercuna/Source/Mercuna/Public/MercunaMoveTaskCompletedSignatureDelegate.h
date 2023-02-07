#pragma once
#include "CoreMinimal.h"
#include "EMercunaMoveResult.h"
#include "MercunaMoveTaskCompletedSignatureDelegate.generated.h"

class AAIController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMercunaMoveTaskCompletedSignature, TEnumAsByte<EMercunaMoveResult::Type>, Result, AAIController*, AIController);

