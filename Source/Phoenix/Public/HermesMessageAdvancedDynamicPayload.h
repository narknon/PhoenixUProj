#pragma once
#include "CoreMinimal.h"
#include "EHermesMessageAdvancedDynamicPayloadType.h"
#include "HermesMessageAdvancedDynamicPayload.generated.h"

USTRUCT(BlueprintType)
struct FHermesMessageAdvancedDynamicPayload {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHermesMessageAdvancedDynamicPayloadType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Boolean;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Integer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scalar;
    
    PHOENIX_API FHermesMessageAdvancedDynamicPayload();
};

