#pragma once
#include "CoreMinimal.h"
#include "OdcFlagsDefinition.generated.h"

USTRUCT(BlueprintType)
struct FOdcFlagsDefinition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> flags;
    
public:
    ODYSSEYRUNTIME_API FOdcFlagsDefinition();
};

