#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SetParameterValue.h"
#include "SetVectorParameterValue.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USetVectorParameterValue : public USetParameterValue {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor m_Vector;
    
public:
    USetVectorParameterValue();
};

