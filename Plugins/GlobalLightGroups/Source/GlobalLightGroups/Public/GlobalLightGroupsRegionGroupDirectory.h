#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GlobalLightGroupsRegionGroupDirectory.generated.h"

class UGlobalLightGroupsRegionGroupRegistry;
class UGlobalLightGroupsWorldRegionGroupMap;

UCLASS(Blueprintable)
class GLOBALLIGHTGROUPS_API UGlobalLightGroupsRegionGroupDirectory : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightGroupsRegionGroupRegistry* Registry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightGroupsWorldRegionGroupMap* WorldRegionGroupMap;
    
    UGlobalLightGroupsRegionGroupDirectory();
};

