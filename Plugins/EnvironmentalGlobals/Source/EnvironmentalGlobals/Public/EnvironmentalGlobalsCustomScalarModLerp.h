#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsCustomScalarMod.h"
#include "EnvironmentalGlobalsCustomScalarModLerp.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UEnvironmentalGlobalsCustomScalarModLerp : public UEnvironmentalGlobalsCustomScalarMod {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ValueAtZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ValueAtOne;
    
    UEnvironmentalGlobalsCustomScalarModLerp();
};

