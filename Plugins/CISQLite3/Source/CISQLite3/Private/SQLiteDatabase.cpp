#include "SQLiteDatabase.h"

class UObject;

bool USQLiteDatabase::Vacuum(const FString& DatabaseName) {
    return false;
}

bool USQLiteDatabase::TruncateTable(const FString& DatabaseName, const FString& TableName) {
    return false;
}

bool USQLiteDatabase::RegisterDatabase(const FString& Name, const FString& Filename, bool RelativeToGameContentDirectory, bool InMemoryDatabase) {
    return false;
}

bool USQLiteDatabase::IsTableExists(const FString& DatabaseName, const FString& TableName) {
    return false;
}

bool USQLiteDatabase::IsDatabaseRegistered(const FString& DatabaseName) {
    return false;
}

void USQLiteDatabase::InsertRowsIntoTable(const FString& DatabaseName, const FString& TableName, const TArray<FSQLiteTableRowSimulator>& rowsOfFields) {
}

bool USQLiteDatabase::GetDataIntoObjectBP(const FSQLiteDatabaseReference& DataSource, const TArray<FString>& Fields, const FSQLiteQueryFinalizedQuery& Query, UObject* ObjectToPopulate) {
    return false;
}

bool USQLiteDatabase::GetDataIntoObject(const FString& DatabaseName, const FString& Query, UObject* ObjectToPopulate) {
    return false;
}

FSQLiteQueryResult USQLiteDatabase::GetDataBP(const FSQLiteDatabaseReference& DataSource, const TArray<FString>& Fields, const FSQLiteQueryFinalizedQuery& Query, int32 MaxResults, int32 ResultOffset) {
    return FSQLiteQueryResult{};
}

FSQLiteQueryResult USQLiteDatabase::GetData(const FString& DatabaseName, const FString& Query) {
    return FSQLiteQueryResult{};
}

bool USQLiteDatabase::ExecSql(const FString& DatabaseName, const FString& Query) {
    return false;
}

bool USQLiteDatabase::DropTable(const FString& DatabaseName, const FString& TableName) {
    return false;
}

bool USQLiteDatabase::DropIndex(const FString& DatabaseName, const FString& IndexName) {
    return false;
}

FSQLiteTable USQLiteDatabase::CreateTable(const FString& DatabaseName, const FString& TableName, const TArray<FSQLiteTableField>& Fields, const FSQLitePrimaryKey& PK) {
    return FSQLiteTable{};
}

bool USQLiteDatabase::CreateIndexes(const FString& DatabaseName, const FString& TableName, const TArray<FSQLiteIndex>& Indexes) {
    return false;
}

bool USQLiteDatabase::CreateIndex(const FString& DatabaseName, const FString& TableName, const FSQLiteIndex Index) {
    return false;
}

USQLiteDatabase::USQLiteDatabase() {
}

