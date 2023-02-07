#pragma once
#include "CoreMinimal.h"
#include "EEvaluatorRootMotion.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EEvaluatorRootMotion -FallbackName=EEvaluatorRootMotion
#include "AblRootMode.generated.h"

USTRUCT(BlueprintType)
struct ABLECORE_API FAblRootMode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEvaluatorRootMotion::Type> m_UseSourceRootMotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEvaluatorRootMotion::Type> m_UseDestRootMotion;
    
    FAblRootMode();
};

