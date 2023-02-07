#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsRegionName.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsRegionName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsRegionName();
};

