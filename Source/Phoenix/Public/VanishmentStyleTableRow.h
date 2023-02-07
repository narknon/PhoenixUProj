#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "VanishmentStyleTableRow.generated.h"

class AVanishmentStyleBase;

USTRUCT(BlueprintType)
struct FVanishmentStyleTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AVanishmentStyleBase> EffectClass;
    
    PHOENIX_API FVanishmentStyleTableRow();
};

