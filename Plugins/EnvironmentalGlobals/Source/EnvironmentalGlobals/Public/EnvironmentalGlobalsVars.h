#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ExposureExpressions.h"
#include "Interface_ExposureExpressionsGlobals.h"
#include "EnvironmentalGlobalsVars.generated.h"

class UEnvironmentalGlobalsVar;

UCLASS(Blueprintable)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsVars : public UDataAsset, public IInterface_ExposureExpressionsGlobals {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UEnvironmentalGlobalsVar*> Vars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressions GlobalExpressions;
    
    UEnvironmentalGlobalsVars();
    
    // Fix for true pure virtual functions not being implemented
};

