#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsScalarConversion.h"
#include "EnvironmentalGlobalsScalarClamp.generated.h"

USTRUCT(BlueprintType)
struct FEnvironmentalGlobalsScalarClamp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ClampMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ClampMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnvironmentalGlobalsScalarConversion ClampMinMaxConversion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseMin: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseMax: 1;
    
    ENVIRONMENTALGLOBALS_API FEnvironmentalGlobalsScalarClamp();
};

