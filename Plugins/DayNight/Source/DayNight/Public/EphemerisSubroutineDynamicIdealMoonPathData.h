#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MoonPath.h"
#include "EphemerisSubroutineDynamicIdealMoonPathData.generated.h"

UCLASS(Blueprintable, Transient)
class DAYNIGHT_API UEphemerisSubroutineDynamicIdealMoonPathData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMoonPath MoonPath;
    
    UEphemerisSubroutineDynamicIdealMoonPathData();
};

