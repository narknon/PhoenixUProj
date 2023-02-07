#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GlobalLightGroupsRegion.h"
#include "GlobalLightGroupsRegionEventDelegate.h"
#include "LightComponentSchedules.h"
#include "GlobalLightGroupsMaster.generated.h"

class UGlobalLightGroupsRegionGroupMap;

UCLASS(Blueprintable, NotPlaceable, Transient)
class GLOBALLIGHTGROUPS_API AGlobalLightGroupsMaster : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGlobalLightGroupsRegionGroupMap* RegionGroupMap;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsRegionEvent RegionEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGlobalLightGroupsRegion> RegionMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightComponentSchedules LightComponentSchedules;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LastRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActiveRegion;
    
public:
    AGlobalLightGroupsMaster();
};

