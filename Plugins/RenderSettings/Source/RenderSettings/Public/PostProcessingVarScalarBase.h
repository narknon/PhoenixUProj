#pragma once
#include "CoreMinimal.h"
#include "EPostProcessingVarScalar.h"
#include "PostProcessingVar.h"
#include "PostProcessingVarScalarBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UPostProcessingVarScalarBase : public UPostProcessingVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPostProcessingVarScalar Var;
    
    UPostProcessingVarScalarBase();
};

