#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsGroupName.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsGroupName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsGroupName();
};

