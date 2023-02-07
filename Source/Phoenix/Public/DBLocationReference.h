#pragma once
#include "CoreMinimal.h"
#include "DBLocationReference.generated.h"

USTRUCT(BlueprintType)
struct FDBLocationReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LocationName;
    
    PHOENIX_API FDBLocationReference();
};

