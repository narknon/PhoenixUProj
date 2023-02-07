#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CinematicBatchRow.generated.h"

class UCinematicBatch;

USTRUCT(BlueprintType)
struct FCinematicBatchRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UCinematicBatch> CinematicBatch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    PHOENIX_API FCinematicBatchRow();
};

