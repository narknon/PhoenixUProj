#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsCustomScalarModsBase.h"
#include "EnvironmentalGlobalsCustomScalarBlendDomain.generated.h"

class URenderSettingsCustomBlendDomain;

UCLASS(Blueprintable, EditInlineNew)
class UEnvironmentalGlobalsCustomScalarBlendDomain : public UEnvironmentalGlobalsCustomScalarModsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* BlendDomain;
    
    UEnvironmentalGlobalsCustomScalarBlendDomain();
};

