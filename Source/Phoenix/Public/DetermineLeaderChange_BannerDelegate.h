#pragma once
#include "CoreMinimal.h"
#include "DetermineLeaderChange_BannerDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FDetermineLeaderChange_Banner, const FName, HouseLeader, const float, GryffindorHousePoints, const float, RavenclawHousePoints, const float, SlytherinHousePoints, const float, HufflepuffHousePoints);

