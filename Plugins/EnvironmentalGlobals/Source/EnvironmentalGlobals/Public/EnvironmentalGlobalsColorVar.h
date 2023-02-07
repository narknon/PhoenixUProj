#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsColorRunMode.h"
#include "EnvironmentalGlobalsVar.h"
#include "EnvironmentalGlobalsColorVar.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsColorVar : public UEnvironmentalGlobalsVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ParameterName;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsColorRunMode RunMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyToMaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyToNiagaraParameterCollection;
    
    UEnvironmentalGlobalsColorVar();
};

