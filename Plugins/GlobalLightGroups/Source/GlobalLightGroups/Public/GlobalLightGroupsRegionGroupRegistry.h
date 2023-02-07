#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GlobalLightGroupsRegionGroups.h"
#include "GlobalLightGroupsRegionGroupRegistry.generated.h"

class UGlobalLightGroupsNamedLightComponentSchedules;

UCLASS(Blueprintable)
class GLOBALLIGHTGROUPS_API UGlobalLightGroupsRegionGroupRegistry : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobalLightGroupsRegionGroups> RegionGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightGroupsNamedLightComponentSchedules* RegionFreeLightComponentSchedules;
    
    UGlobalLightGroupsRegionGroupRegistry();
};

