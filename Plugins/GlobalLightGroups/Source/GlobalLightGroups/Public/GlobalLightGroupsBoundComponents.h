#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsBoundComponentList.h"
#include "GlobalLightGroupsMask.h"
#include "GlobalLightGroupsBoundComponents.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTGROUPS_API FGlobalLightGroupsBoundComponents {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobalLightGroupsBoundComponentList> ComponentGroups;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsMask LastLightMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsMask ForceUpdateMask;
    
public:
    FGlobalLightGroupsBoundComponents();
};

