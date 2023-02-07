#pragma once
#include "CoreMinimal.h"
#include "EMoonPathMode.h"
#include "EphemerisSubroutine.h"
#include "EphemerisSubroutineFixedIdealMoonPath.generated.h"

class UFixedIdealMoonPathData;

UCLASS(Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineFixedIdealMoonPath : public UEphemerisSubroutine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFixedIdealMoonPathData* MoonPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMoonPathMode AzimuthMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AzimuthOffsetDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UEphemerisSubroutineFixedIdealMoonPath();
};

