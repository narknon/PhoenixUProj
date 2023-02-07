#pragma once
#include "CoreMinimal.h"
#include "EphemerisSubroutine.h"
#include "ManualMoonSetup.h"
#include "EphemerisSubroutineForceMoonPhase.generated.h"

UCLASS(Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineForceMoonPhase : public UEphemerisSubroutine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FManualMoonSetup Moon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UEphemerisSubroutineForceMoonPhase();
};

