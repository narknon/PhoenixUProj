#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RegionBannerData.h"
#include "CleanNameToDisplayName.generated.h"

UCLASS(Blueprintable)
class UCleanNameToDisplayName : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FRegionBannerData> CleanNameToDisplayNameMap;
    
    UCleanNameToDisplayName();
};

