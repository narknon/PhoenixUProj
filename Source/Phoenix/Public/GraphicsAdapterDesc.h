#pragma once
#include "CoreMinimal.h"
#include "GraphicsAdapterDesc.generated.h"

USTRUCT(BlueprintType)
struct FGraphicsAdapterDesc {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LUIDLow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LUIDHigh;
    
    PHOENIX_API FGraphicsAdapterDesc();
};

