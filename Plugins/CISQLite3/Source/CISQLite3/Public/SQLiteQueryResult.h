#pragma once
#include "CoreMinimal.h"
#include "SQLiteQueryResultRow.h"
#include "SQLiteQueryResult.generated.h"

USTRUCT(BlueprintType)
struct CISQLITE3_API FSQLiteQueryResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSQLiteQueryResultRow> ResultRows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Success;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ErrorMessage;
    
    FSQLiteQueryResult();
};

