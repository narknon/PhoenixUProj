#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "AvatarPresetColorInfo.generated.h"

USTRUCT(BlueprintType)
struct FAvatarPresetColorInfo : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    PHOENIX_API FAvatarPresetColorInfo();
};

