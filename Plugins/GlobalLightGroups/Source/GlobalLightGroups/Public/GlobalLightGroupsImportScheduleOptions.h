#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightGroupsImportScheduleType.h"
#include "GlobalLightGroupsImportScheduleOptionsAdvanced.h"
#include "GlobalLightGroupsImportScheduleOptions.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsImportScheduleOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightGroupsImportScheduleType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsImportScheduleOptionsAdvanced Advanced;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsImportScheduleOptions();
};

