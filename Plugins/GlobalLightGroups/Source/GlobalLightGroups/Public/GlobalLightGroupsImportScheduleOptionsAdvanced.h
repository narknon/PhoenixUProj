#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsImportScheduleOptionsAdvanced.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsImportScheduleOptionsAdvanced {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName KeyNameFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OverrideKeyNames;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsImportScheduleOptionsAdvanced();
};

