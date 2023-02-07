#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MultiFX2_MaterialParameterBase.h"
#include "MultiFX2_MaterialParameterVector.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_MaterialParameterVector : public UMultiFX2_MaterialParameterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector VectorParameter;
    
public:
    UMultiFX2_MaterialParameterVector();
};

