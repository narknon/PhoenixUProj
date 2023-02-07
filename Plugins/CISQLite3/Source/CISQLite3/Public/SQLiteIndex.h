#pragma once
#include "CoreMinimal.h"
#include "SQLiteIndex.generated.h"

USTRUCT(BlueprintType)
struct CISQLITE3_API FSQLiteIndex {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ResultStr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString IndexName;
    
    FSQLiteIndex();
};

