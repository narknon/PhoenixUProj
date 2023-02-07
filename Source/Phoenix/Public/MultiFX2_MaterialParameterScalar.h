#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_MaterialParameterBase.h"
#include "MultiFX2_MaterialParameterScalar.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_MaterialParameterScalar : public UMultiFX2_MaterialParameterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScalarParameter;
    
public:
    UMultiFX2_MaterialParameterScalar();
};

