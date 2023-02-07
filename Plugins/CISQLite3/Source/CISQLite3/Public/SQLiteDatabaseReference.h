#pragma once
#include "CoreMinimal.h"
#include "SQLiteDatabaseReference.generated.h"

USTRUCT(BlueprintType)
struct CISQLITE3_API FSQLiteDatabaseReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DatabaseName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> Tables;
    
    FSQLiteDatabaseReference();
};

