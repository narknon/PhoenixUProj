#pragma once
#include "CoreMinimal.h"
#include "CachedMIDParameter.h"
#include "CachedMIDParameterScalar.generated.h"

USTRUCT(BlueprintType)
struct AVARENDERTECH_API FCachedMIDParameterScalar : public FCachedMIDParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    FCachedMIDParameterScalar();
};

