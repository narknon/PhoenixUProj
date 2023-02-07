#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsImportScheduleOptions.h"
#include "GlobalLightGroupsImportScheduleTable.generated.h"

class UDataTable;

USTRUCT(BlueprintType)
struct FGlobalLightGroupsImportScheduleTable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* ScheduleTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsImportScheduleOptions ImportOptions;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsImportScheduleTable();
};

