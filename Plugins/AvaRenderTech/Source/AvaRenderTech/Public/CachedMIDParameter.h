#pragma once
#include "CoreMinimal.h"
#include "CachedMIDParameter.generated.h"

USTRUCT(BlueprintType)
struct FCachedMIDParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    AVARENDERTECH_API FCachedMIDParameter();
};

