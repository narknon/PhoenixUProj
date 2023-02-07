#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AblSetParameterValue.h"
#include "AblSetVectorParameterValue.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetVectorParameterValue : public UAblSetParameterValue {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor m_Vector;
    
public:
    UAblSetVectorParameterValue();
};

