#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsScalarRunMode.h"
#include "EnvironmentalGlobalsVar.h"
#include "EnvironmentalGlobalsScalarVar.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsScalarVar : public UEnvironmentalGlobalsVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ParameterName;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsScalarRunMode RunMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyToMaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyToNiagaraParameterCollection;
    
    UEnvironmentalGlobalsScalarVar();
};

