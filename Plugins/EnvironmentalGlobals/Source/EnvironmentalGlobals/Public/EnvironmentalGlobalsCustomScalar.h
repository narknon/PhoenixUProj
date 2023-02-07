#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsScalarVar.h"
#include "EnvironmentalGlobalsCustomScalar.generated.h"

class UEnvironmentalGlobalsCustomScalarBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsCustomScalar : public UEnvironmentalGlobalsScalarVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnvironmentalGlobalsCustomScalarBase* Scalar;
    
    UEnvironmentalGlobalsCustomScalar();
};

