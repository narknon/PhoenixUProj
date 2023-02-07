#pragma once
#include "CoreMinimal.h"
#include "PostProcessingVarScalarBase.h"
#include "PostProcessingVarScalarConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UPostProcessingVarScalarConstant : public UPostProcessingVarScalarBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPostProcessingVarScalarConstant();
};

