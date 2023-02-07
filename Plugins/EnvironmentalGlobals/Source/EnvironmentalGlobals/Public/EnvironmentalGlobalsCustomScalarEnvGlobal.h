#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsValue.h"
#include "EnvironmentalGlobalsCustomScalarModsBase.h"
#include "EnvironmentalGlobalsCustomScalarEnvGlobal.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsCustomScalarEnvGlobal : public UEnvironmentalGlobalsCustomScalarModsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnvironmentalGlobalsValue Value;
    
    UEnvironmentalGlobalsCustomScalarEnvGlobal();
};

