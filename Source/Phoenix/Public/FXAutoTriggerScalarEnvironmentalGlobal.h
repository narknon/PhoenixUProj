#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsScalarName.h"
#include "FXAutoTriggerScalar.h"
#include "FXAutoTriggerScalarEnvironmentalGlobal.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarEnvironmentalGlobal : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsScalarName EnvironmentalGlobal;
    
    UFXAutoTriggerScalarEnvironmentalGlobal();
};

