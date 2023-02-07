#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsBoundComponents.h"
#include "GlobalLightGroupsGroupSchedules.h"
#include "GlobalLightGroupsMask.h"
#include "GlobalLightGroupsMaskLock.h"
#include "GlobalLightGroupsRegion.generated.h"

class UGlobalLightGroupsGroupNameMap;

USTRUCT(BlueprintType)
struct GLOBALLIGHTGROUPS_API FGlobalLightGroupsRegion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsGroupSchedules GroupSchedules;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightGroupsGroupNameMap* GroupNameMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsBoundComponents BoundComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsMask LightMaskTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsMaskLock LockState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsMask LightMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsMask LastMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInitialEventsSent;
    
public:
    FGlobalLightGroupsRegion();
};

