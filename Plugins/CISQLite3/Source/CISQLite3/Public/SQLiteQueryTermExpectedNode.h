#pragma once
#include "CoreMinimal.h"
#include "SQLiteQueryTermExpectedNode.generated.h"

USTRUCT(BlueprintType)
struct CISQLITE3_API FSQLiteQueryTermExpectedNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Query;
    
    FSQLiteQueryTermExpectedNode();
};

