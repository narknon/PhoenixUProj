#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsCustomScalarBase.h"
#include "EnvironmentalGlobalsCustomScalarConstant.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsCustomScalarConstant : public UEnvironmentalGlobalsCustomScalarBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UEnvironmentalGlobalsCustomScalarConstant();
};

