#pragma once
#include "CoreMinimal.h"
#include "SQLitePrimaryKey.h"
#include "SQLiteTableField.h"
#include "SQLiteTable.generated.h"

USTRUCT(BlueprintType)
struct CISQLITE3_API FSQLiteTable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DatabaseName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TableName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSQLiteTableField> Fields;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSQLitePrimaryKey PK;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Created;
    
    FSQLiteTable();
};

