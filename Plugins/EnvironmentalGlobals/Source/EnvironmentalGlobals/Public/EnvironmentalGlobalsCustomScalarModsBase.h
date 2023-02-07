#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsCustomScalarBase.h"
#include "EnvironmentalGlobalsCustomScalarModsBase.generated.h"

class UEnvironmentalGlobalsCustomScalarMod;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsCustomScalarModsBase : public UEnvironmentalGlobalsCustomScalarBase {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UEnvironmentalGlobalsCustomScalarMod*> Mods;
    
    UEnvironmentalGlobalsCustomScalarModsBase();
};

