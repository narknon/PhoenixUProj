#pragma once
#include "CoreMinimal.h"
#include "SQLiteQueryResult.h"
#include "SQLiteQueryResultMap.h"
#include "UObject/Object.h"
#include "DbGateway.generated.h"

UCLASS(Blueprintable)
class DBGATEWAY_API UDbGateway : public UObject {
    GENERATED_BODY()
public:
    UDbGateway();
    UFUNCTION(BlueprintCallable)
    static bool DbWriteMiscSaveDataItem(const FString& InOwner, const FString& InName, const FString& InValue, bool InBackupNow);
    
    UFUNCTION(BlueprintCallable)
    static bool DbRemoveMiscSaveDataItem(const FString& InOwner, const FString& InName, const FString& InCallerName);
    
    UFUNCTION(BlueprintCallable)
    static bool DbRemoveAllMiscSaveDataItems(const FString& InOwner, const FString& InCallerName);
    
private:
    UFUNCTION(BlueprintCallable)
    static bool DbReloadDynDB();
    
public:
    UFUNCTION(BlueprintCallable)
    static bool DbReadMiscSaveDataItem(const FString& InOwner, const FString& InName, FString& OutValue);
    
    UFUNCTION(BlueprintCallable)
    static bool DbReadMiscSaveDataForOwner(const FString& InOwner, FSQLiteQueryResult& OutQueryResults);
    
    UFUNCTION(BlueprintCallable)
    static bool DbQuerySingleColumnStrings(const FString& InQuery, TArray<FString>& OutQueryResults);
    
    UFUNCTION(BlueprintCallable)
    static bool DbQueryMap(const FString& InQuery, FSQLiteQueryResultMap& OutQueryResults, bool inIgnoreDUPs);
    
    UFUNCTION(BlueprintCallable)
    static bool DbQuery(const FString& InQuery, FSQLiteQueryResult& OutQueryResults);
    
    UFUNCTION(BlueprintCallable)
    static bool DbPutDynDBImage(TArray<uint8>& RawDbImage);
    
    UFUNCTION(BlueprintCallable)
    static bool DbOperate(const FString& InTransaction, bool InBackupNow);
    
    UFUNCTION(BlueprintCallable)
    static bool DbGetDynDBImage(TArray<uint8>& RawDbImage);
    
private:
    UFUNCTION(BlueprintCallable)
    static bool DbEditorQueryMap(const FString& InQuery, FSQLiteQueryResultMap& OutQueryResults, bool inIgnoreDUPs);
    
    UFUNCTION(BlueprintCallable)
    static bool DbEditorQuery(const FString& InQuery, FSQLiteQueryResult& OutQueryResults);
    
    UFUNCTION(BlueprintCallable)
    static bool DbEditorOperate(const FString& InTransaction, int32& outNumRowsChanged, const FString& inTableName);
    
};

