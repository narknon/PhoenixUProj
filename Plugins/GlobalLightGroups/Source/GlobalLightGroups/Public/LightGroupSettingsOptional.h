#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsGroupName.h"
#include "LightGroupSettingsOptional.generated.h"

USTRUCT(BlueprintType)
struct FLightGroupSettingsOptional {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Region;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsGroupName Group;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetGroup;
    
    GLOBALLIGHTGROUPS_API FLightGroupSettingsOptional();
};

