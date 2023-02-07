#pragma once
#include "CoreMinimal.h"
#include "AblSetParameterValue.h"
#include "AblSetScalarParameterValue.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetScalarParameterValue : public UAblSetParameterValue {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_Scalar;
    
public:
    UAblSetScalarParameterValue();
};

