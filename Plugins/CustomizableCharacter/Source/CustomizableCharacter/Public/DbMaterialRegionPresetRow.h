#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DbMaterialRegionPresetRow.generated.h"

USTRUCT(BlueprintType)
struct FDbMaterialRegionPresetRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FString> Params;
    
    CUSTOMIZABLECHARACTER_API FDbMaterialRegionPresetRow();
};

