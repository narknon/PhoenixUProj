#pragma once
#include "CoreMinimal.h"
#include "AblBlendTimes.generated.h"

USTRUCT(BlueprintType)
struct ABLECORE_API FAblBlendTimes {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_BlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_BlendOut;
    
    FAblBlendTimes();
};

