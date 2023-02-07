#pragma once
#include "CoreMinimal.h"
#include "EMoonPathMode.h"
#include "EphemerisSubroutine.h"
#include "MoonPathSettings.h"
#include "EphemerisSubroutineDynamicIdealMoonPath.generated.h"

UCLASS(Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineDynamicIdealMoonPath : public UEphemerisSubroutine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMoonPathMode AzimuthMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AzimuthOffsetDegrees;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMoonPathSettings PathSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UEphemerisSubroutineDynamicIdealMoonPath();
};

