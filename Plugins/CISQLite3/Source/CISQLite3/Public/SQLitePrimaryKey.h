#pragma once
#include "CoreMinimal.h"
#include "SQLitePrimaryKey.generated.h"

USTRUCT(BlueprintType)
struct CISQLITE3_API FSQLitePrimaryKey {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ResultStr;
    
    FSQLitePrimaryKey();
};

