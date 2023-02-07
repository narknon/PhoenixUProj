#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LakeParameterGeneratorBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class FLOW_API ULakeParameterGeneratorBase : public UObject {
    GENERATED_BODY()
public:
    ULakeParameterGeneratorBase();
};

