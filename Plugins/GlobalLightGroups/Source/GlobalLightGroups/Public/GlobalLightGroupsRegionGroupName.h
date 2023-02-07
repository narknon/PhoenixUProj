#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsRegionGroupName.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsRegionGroupName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Region;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsRegionGroupName();
};

