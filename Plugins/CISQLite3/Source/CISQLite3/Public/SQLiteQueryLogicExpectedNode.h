#pragma once
#include "CoreMinimal.h"
#include "SQLiteQueryLogicExpectedNode.generated.h"

USTRUCT(BlueprintType)
struct CISQLITE3_API FSQLiteQueryLogicExpectedNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Query;
    
    FSQLiteQueryLogicExpectedNode();
};

