#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MultiFX2_MaterialParameterBase.h"
#include "MultiFX2_MaterialParameterColor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_MaterialParameterColor : public UMultiFX2_MaterialParameterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ColorParameter;
    
public:
    UMultiFX2_MaterialParameterColor();
};

