#include "DbGateway.h"

bool UDbGateway::DbWriteMiscSaveDataItem(const FString& InOwner, const FString& InName, const FString& InValue, bool InBackupNow) {
    return false;
}

bool UDbGateway::DbRemoveMiscSaveDataItem(const FString& InOwner, const FString& InName, const FString& InCallerName) {
    return false;
}

bool UDbGateway::DbRemoveAllMiscSaveDataItems(const FString& InOwner, const FString& InCallerName) {
    return false;
}

bool UDbGateway::DbReloadDynDB() {
    return false;
}

bool UDbGateway::DbReadMiscSaveDataItem(const FString& InOwner, const FString& InName, FString& OutValue) {
    return false;
}

bool UDbGateway::DbReadMiscSaveDataForOwner(const FString& InOwner, FSQLiteQueryResult& OutQueryResults) {
    return false;
}

bool UDbGateway::DbQuerySingleColumnStrings(const FString& InQuery, TArray<FString>& OutQueryResults) {
    return false;
}

bool UDbGateway::DbQueryMap(const FString& InQuery, FSQLiteQueryResultMap& OutQueryResults, bool inIgnoreDUPs) {
    return false;
}

bool UDbGateway::DbQuery(const FString& InQuery, FSQLiteQueryResult& OutQueryResults) {
    return false;
}

bool UDbGateway::DbPutDynDBImage(TArray<uint8>& RawDbImage) {
    return false;
}

bool UDbGateway::DbOperate(const FString& InTransaction, bool InBackupNow) {
    return false;
}

bool UDbGateway::DbGetDynDBImage(TArray<uint8>& RawDbImage) {
    return false;
}

bool UDbGateway::DbEditorQueryMap(const FString& InQuery, FSQLiteQueryResultMap& OutQueryResults, bool inIgnoreDUPs) {
    return false;
}

bool UDbGateway::DbEditorQuery(const FString& InQuery, FSQLiteQueryResult& OutQueryResults) {
    return false;
}

bool UDbGateway::DbEditorOperate(const FString& InTransaction, int32& outNumRowsChanged, const FString& inTableName) {
    return false;
}

UDbGateway::UDbGateway() {
}

