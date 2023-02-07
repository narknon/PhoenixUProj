#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsGroupName.h"
#include "LightGroupSettings.generated.h"

USTRUCT(BlueprintType)
struct FLightGroupSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Region;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsGroupName Group;
    
    GLOBALLIGHTGROUPS_API FLightGroupSettings();
};

