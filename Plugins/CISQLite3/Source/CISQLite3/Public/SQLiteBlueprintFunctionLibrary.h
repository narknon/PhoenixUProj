#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SQLiteIndex.h"
#include "SQLitePrimaryKey.h"
#include "SQLiteQueryFinalizedQuery.h"
#include "SQLiteQueryLogicExpectedNode.h"
#include "SQLiteQueryTermExpectedNode.h"
#include "SQLiteTableField.h"
#include "SQLiteBlueprintFunctionLibrary.generated.h"

UCLASS(Blueprintable)
class CISQLITE3_API USQLiteBlueprintFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USQLiteBlueprintFunctionLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSQLiteTableField SQLiteTEXT(const FString& FieldName, const bool PK, const bool Unique);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSQLiteTableField SQLiteREAL(const FString& FieldName, const bool PK, const bool Unique);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSQLitePrimaryKey SQLitePrimaryKey(const TArray<FSQLiteTableField> Fields);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSQLiteTableField SQLiteNUMERIC(const FString& FieldName, const bool PK, const bool Unique);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSQLiteTableField SQLiteINTEGER(const FString& FieldName, const bool PK, const bool AI, const bool Unique);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSQLiteIndex SQLiteIndexFunction(const TArray<FSQLiteTableField> Fields, const FString& idxName, bool Unique);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSQLiteQueryLogicExpectedNode QueryTerm(const FSQLiteQueryTermExpectedNode& LogicOperation, const FString& Field, const FString& Operator, const FString& Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSQLiteQueryTermExpectedNode QueryStart(FSQLiteQueryTermExpectedNode LogicOperationOrNone);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSQLiteQueryTermExpectedNode QueryLogicOr(const FSQLiteQueryLogicExpectedNode& LHS);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSQLiteQueryTermExpectedNode QueryLogicAnd(const FSQLiteQueryLogicExpectedNode& LHS);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSQLiteQueryFinalizedQuery QueryFinal(const FSQLiteQueryLogicExpectedNode& QueryEndNode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSQLiteQueryLogicExpectedNode QueryEnd(const FSQLiteQueryLogicExpectedNode& LastQueryTerm);
    
    UFUNCTION(BlueprintCallable)
    static int32 CastToInt(const FString& SQLiteResultValue);
    
    UFUNCTION(BlueprintCallable)
    static float CastToFloat(const FString& SQLiteResultValue);
    
    UFUNCTION(BlueprintCallable)
    static bool CastToBoolean(const FString& SQLiteResultValue);
    
};

