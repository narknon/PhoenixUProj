#pragma once
#include "CoreMinimal.h"
#include "EPostProcessingVarColor.h"
#include "PostProcessingVar.h"
#include "PostProcessingVarColorBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UPostProcessingVarColorBase : public UPostProcessingVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPostProcessingVarColor Var;
    
    UPostProcessingVarColorBase();
};

