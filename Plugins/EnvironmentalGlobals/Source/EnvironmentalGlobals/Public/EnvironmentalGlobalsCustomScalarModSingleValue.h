#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsCustomScalarMod.h"
#include "EnvironmentalGlobalsCustomScalarModSingleValue.generated.h"

class UEnvironmentalGlobalsCustomScalarBase;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UEnvironmentalGlobalsCustomScalarModSingleValue : public UEnvironmentalGlobalsCustomScalarMod {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnvironmentalGlobalsCustomScalarBase* Value;
    
    UEnvironmentalGlobalsCustomScalarModSingleValue();
};

