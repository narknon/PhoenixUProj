#pragma once
#include "CoreMinimal.h"
#include "OdcNavGraphImage.generated.h"

USTRUCT(BlueprintType)
struct FOdcNavGraphImage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> Data;
    
    ODYSSEYRUNTIME_API FOdcNavGraphImage();
};

