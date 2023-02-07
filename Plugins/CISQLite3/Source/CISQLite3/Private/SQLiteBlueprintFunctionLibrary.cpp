#include "SQLiteBlueprintFunctionLibrary.h"

FSQLiteTableField USQLiteBlueprintFunctionLibrary::SQLiteTEXT(const FString& FieldName, const bool PK, const bool Unique) {
    return FSQLiteTableField{};
}

FSQLiteTableField USQLiteBlueprintFunctionLibrary::SQLiteREAL(const FString& FieldName, const bool PK, const bool Unique) {
    return FSQLiteTableField{};
}

FSQLitePrimaryKey USQLiteBlueprintFunctionLibrary::SQLitePrimaryKey(const TArray<FSQLiteTableField> Fields) {
    return FSQLitePrimaryKey{};
}

FSQLiteTableField USQLiteBlueprintFunctionLibrary::SQLiteNUMERIC(const FString& FieldName, const bool PK, const bool Unique) {
    return FSQLiteTableField{};
}

FSQLiteTableField USQLiteBlueprintFunctionLibrary::SQLiteINTEGER(const FString& FieldName, const bool PK, const bool AI, const bool Unique) {
    return FSQLiteTableField{};
}

FSQLiteIndex USQLiteBlueprintFunctionLibrary::SQLiteIndexFunction(const TArray<FSQLiteTableField> Fields, const FString& idxName, bool Unique) {
    return FSQLiteIndex{};
}

FSQLiteQueryLogicExpectedNode USQLiteBlueprintFunctionLibrary::QueryTerm(const FSQLiteQueryTermExpectedNode& LogicOperation, const FString& Field, const FString& Operator, const FString& Value) {
    return FSQLiteQueryLogicExpectedNode{};
}

FSQLiteQueryTermExpectedNode USQLiteBlueprintFunctionLibrary::QueryStart(FSQLiteQueryTermExpectedNode LogicOperationOrNone) {
    return FSQLiteQueryTermExpectedNode{};
}

FSQLiteQueryTermExpectedNode USQLiteBlueprintFunctionLibrary::QueryLogicOr(const FSQLiteQueryLogicExpectedNode& LHS) {
    return FSQLiteQueryTermExpectedNode{};
}

FSQLiteQueryTermExpectedNode USQLiteBlueprintFunctionLibrary::QueryLogicAnd(const FSQLiteQueryLogicExpectedNode& LHS) {
    return FSQLiteQueryTermExpectedNode{};
}

FSQLiteQueryFinalizedQuery USQLiteBlueprintFunctionLibrary::QueryFinal(const FSQLiteQueryLogicExpectedNode& QueryEndNode) {
    return FSQLiteQueryFinalizedQuery{};
}

FSQLiteQueryLogicExpectedNode USQLiteBlueprintFunctionLibrary::QueryEnd(const FSQLiteQueryLogicExpectedNode& LastQueryTerm) {
    return FSQLiteQueryLogicExpectedNode{};
}

int32 USQLiteBlueprintFunctionLibrary::CastToInt(const FString& SQLiteResultValue) {
    return 0;
}

float USQLiteBlueprintFunctionLibrary::CastToFloat(const FString& SQLiteResultValue) {
    return 0.0f;
}

bool USQLiteBlueprintFunctionLibrary::CastToBoolean(const FString& SQLiteResultValue) {
    return false;
}

USQLiteBlueprintFunctionLibrary::USQLiteBlueprintFunctionLibrary() {
}

