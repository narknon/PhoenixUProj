#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "QueryFinishedData.h"
#include "RunEQS_FinishedDelegateDelegate.generated.h"

class ASocialReasoning;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FRunEQS_FinishedDelegate, const ASocialReasoning*, SocialReasoning, EEnvQueryRunMode::Type, RunMode, const FQueryFinishedData&, QueryFinishedDelegate);

