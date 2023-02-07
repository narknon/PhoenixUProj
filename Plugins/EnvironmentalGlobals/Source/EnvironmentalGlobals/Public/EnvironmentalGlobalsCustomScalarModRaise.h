#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsCustomScalarMod.h"
#include "EnvironmentalGlobalsCustomScalarModRaise.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UEnvironmentalGlobalsCustomScalarModRaise : public UEnvironmentalGlobalsCustomScalarMod {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Base;
    
    UEnvironmentalGlobalsCustomScalarModRaise();
};

