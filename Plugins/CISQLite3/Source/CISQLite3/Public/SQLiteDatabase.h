#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SQLiteDatabaseReference.h"
#include "SQLiteIndex.h"
#include "SQLitePrimaryKey.h"
#include "SQLiteQueryFinalizedQuery.h"
#include "SQLiteQueryResult.h"
#include "SQLiteTable.h"
#include "SQLiteTableField.h"
#include "SQLiteTableRowSimulator.h"
#include "SQLiteDatabase.generated.h"

UCLASS(Blueprintable)
class CISQLITE3_API USQLiteDatabase : public UObject {
    GENERATED_BODY()
public:
    USQLiteDatabase();
    UFUNCTION(BlueprintCallable)
    static bool Vacuum(const FString& DatabaseName);
    
    UFUNCTION(BlueprintCallable)
    static bool TruncateTable(const FString& DatabaseName, const FString& TableName);
    
    UFUNCTION(BlueprintCallable)
    static bool RegisterDatabase(const FString& Name, const FString& Filename, bool RelativeToGameContentDirectory, bool InMemoryDatabase);
    
    UFUNCTION(BlueprintCallable)
    static bool IsTableExists(const FString& DatabaseName, const FString& TableName);
    
    UFUNCTION(BlueprintCallable)
    static bool IsDatabaseRegistered(const FString& DatabaseName);
    
    UFUNCTION(BlueprintCallable)
    static void InsertRowsIntoTable(const FString& DatabaseName, const FString& TableName, const TArray<FSQLiteTableRowSimulator>& rowsOfFields);
    
    UFUNCTION(BlueprintCallable)
    static bool GetDataIntoObjectBP(const FSQLiteDatabaseReference& DataSource, const TArray<FString>& Fields, const FSQLiteQueryFinalizedQuery& Query, UObject* ObjectToPopulate);
    
    UFUNCTION(BlueprintCallable)
    static bool GetDataIntoObject(const FString& DatabaseName, const FString& Query, UObject* ObjectToPopulate);
    
    UFUNCTION(BlueprintCallable)
    static FSQLiteQueryResult GetDataBP(const FSQLiteDatabaseReference& DataSource, const TArray<FString>& Fields, const FSQLiteQueryFinalizedQuery& Query, int32 MaxResults, int32 ResultOffset);
    
    UFUNCTION(BlueprintCallable)
    static FSQLiteQueryResult GetData(const FString& DatabaseName, const FString& Query);
    
    UFUNCTION(BlueprintCallable)
    static bool ExecSql(const FString& DatabaseName, const FString& Query);
    
    UFUNCTION(BlueprintCallable)
    static bool DropTable(const FString& DatabaseName, const FString& TableName);
    
    UFUNCTION(BlueprintCallable)
    static bool DropIndex(const FString& DatabaseName, const FString& IndexName);
    
    UFUNCTION(BlueprintCallable)
    static FSQLiteTable CreateTable(const FString& DatabaseName, const FString& TableName, const TArray<FSQLiteTableField>& Fields, const FSQLitePrimaryKey& PK);
    
    UFUNCTION(BlueprintCallable)
    static bool CreateIndexes(const FString& DatabaseName, const FString& TableName, const TArray<FSQLiteIndex>& Indexes);
    
    UFUNCTION(BlueprintCallable)
    static bool CreateIndex(const FString& DatabaseName, const FString& TableName, const FSQLiteIndex Index);
    
};

