#pragma once
#include "CoreMinimal.h"
#include "SQLiteTableField.h"
#include "SQLiteTableRowSimulator.generated.h"

USTRUCT(BlueprintType)
struct CISQLITE3_API FSQLiteTableRowSimulator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSQLiteTableField> rowsOfFields;
    
    FSQLiteTableRowSimulator();
};

