#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GlobalLightGroupsRegionGroupMap.generated.h"

class UGlobalLightGroupsGroupNameMap;

UCLASS(Blueprintable)
class UGlobalLightGroupsRegionGroupMap : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGlobalLightGroupsGroupNameMap*> RegionMap;
    
    UGlobalLightGroupsRegionGroupMap();
};

