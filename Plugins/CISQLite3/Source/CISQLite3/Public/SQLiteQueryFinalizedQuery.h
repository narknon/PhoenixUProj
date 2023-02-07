#pragma once
#include "CoreMinimal.h"
#include "SQLiteQueryFinalizedQuery.generated.h"

USTRUCT(BlueprintType)
struct CISQLITE3_API FSQLiteQueryFinalizedQuery {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Query;
    
    FSQLiteQueryFinalizedQuery();
};

