#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsRegionGroups.generated.h"

class UGlobalLightGroupsNamedGroupSchedules;
class UGlobalLightGroupsNamedLightComponentSchedules;

USTRUCT(BlueprintType)
struct FGlobalLightGroupsRegionGroups {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Region;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<FName> Groups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightGroupsNamedGroupSchedules* GroupSchedules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightGroupsNamedLightComponentSchedules* LightComponentSchedules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceGroup0OffGroup1On;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsRegionGroups();
};

