#pragma once
#include "CoreMinimal.h"
#include "GeneratedHandle.generated.h"

USTRUCT(BlueprintType)
struct FGeneratedHandle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Handle;
    
    UTILITIESRUNTIME_API FGeneratedHandle();
};

