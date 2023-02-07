#pragma once
#include "CoreMinimal.h"
#include "DatabaseLockList.generated.h"

USTRUCT(BlueprintType)
struct FDatabaseLockList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    PHOENIX_API FDatabaseLockList();
};

