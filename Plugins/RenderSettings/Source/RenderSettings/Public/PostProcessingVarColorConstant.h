#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PostProcessingVarColorBase.h"
#include "PostProcessingVarColorConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UPostProcessingVarColorConstant : public UPostProcessingVarColorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Value;
    
    UPostProcessingVarColorConstant();
};

