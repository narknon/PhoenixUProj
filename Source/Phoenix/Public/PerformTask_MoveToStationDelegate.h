#pragma once
#include "CoreMinimal.h"
#include "EStationInteraction.h"
#include "PerformTask_MoveToStationDelegate.generated.h"

class ASocialReasoning;
class UStationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(FPerformTask_MoveToStation, const ASocialReasoning*, SocialReasoning, const UStationComponent*, InStation, const EStationInteraction, InStationInteractionType, const FName, InActionName, const int32, InConnectionIndex, const float, InStationUseDuration, const bool, InSkipValidationForTeleport);

