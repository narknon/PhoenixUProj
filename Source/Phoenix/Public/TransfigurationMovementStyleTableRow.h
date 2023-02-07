#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TransfigurationMovementStyleTableRow.generated.h"

class ATransfigurationMovementStyleBase;

USTRUCT(BlueprintType)
struct FTransfigurationMovementStyleTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ATransfigurationMovementStyleBase> EffectClass;
    
    PHOENIX_API FTransfigurationMovementStyleTableRow();
};

