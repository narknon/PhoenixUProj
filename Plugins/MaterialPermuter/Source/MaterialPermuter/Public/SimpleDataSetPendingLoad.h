#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SimpleDataSetPendingLoad.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FSimpleDataSetPendingLoad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftObjectPath UniqueId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime Started;
    
    FSimpleDataSetPendingLoad();
};

