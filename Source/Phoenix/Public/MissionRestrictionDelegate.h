#pragma once
#include "CoreMinimal.h"
#include "RestrictionInfo.h"
#include "MissionRestrictionDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FMissionRestriction, const FString&, restrictionType, const FString&, MissionID, FRestrictionInfo&, ioRestrictionInfo, bool&, o_canSpawn);

