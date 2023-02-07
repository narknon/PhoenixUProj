#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_MaterialParameterBase.h"
#include "MultiFX2_MaterialParameterCurve.generated.h"

class UCurveBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_MaterialParameterCurve : public UMultiFX2_MaterialParameterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveBase* CurveParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateRate;
    
public:
    UMultiFX2_MaterialParameterCurve();
};

