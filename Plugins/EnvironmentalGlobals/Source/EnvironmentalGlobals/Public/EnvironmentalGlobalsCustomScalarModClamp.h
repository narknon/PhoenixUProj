#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsCustomScalarMod.h"
#include "EnvironmentalGlobalsCustomScalarModClamp.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UEnvironmentalGlobalsCustomScalarModClamp : public UEnvironmentalGlobalsCustomScalarMod {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Min;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Max;
    
    UEnvironmentalGlobalsCustomScalarModClamp();
};

