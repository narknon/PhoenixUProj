#pragma once
#include "CoreMinimal.h"
#include "DatabaseName.generated.h"

USTRUCT(BlueprintType)
struct FDatabaseName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DBSubType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DBName;
    
    PHOENIX_API FDatabaseName();
};

