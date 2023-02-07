#pragma once
#include "CoreMinimal.h"
#include "SQLiteKeyValuePair.generated.h"

USTRUCT(BlueprintType)
struct CISQLITE3_API FSQLiteKeyValuePair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Value;
    
    FSQLiteKeyValuePair();
};

