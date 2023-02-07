#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GlobalLightGroupsWorldRegionGroupMap.generated.h"

class UGlobalLightGroupsRegionGroupMap;
class UWorld;

UCLASS(Blueprintable)
class UGlobalLightGroupsWorldRegionGroupMap : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UWorld*, UGlobalLightGroupsRegionGroupMap*> WorldMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightGroupsRegionGroupMap* PresetMap;
    
    UGlobalLightGroupsWorldRegionGroupMap();
};

