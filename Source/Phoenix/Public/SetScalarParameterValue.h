#pragma once
#include "CoreMinimal.h"
#include "SetParameterValue.h"
#include "SetScalarParameterValue.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USetScalarParameterValue : public USetParameterValue {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_Scalar;
    
public:
    USetScalarParameterValue();
};

