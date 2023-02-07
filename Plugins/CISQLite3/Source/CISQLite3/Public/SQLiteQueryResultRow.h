#pragma once
#include "CoreMinimal.h"
#include "SQLiteKeyValuePair.h"
#include "SQLiteQueryResultRow.generated.h"

USTRUCT(BlueprintType)
struct CISQLITE3_API FSQLiteQueryResultRow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSQLiteKeyValuePair> Fields;
    
    FSQLiteQueryResultRow();
};

