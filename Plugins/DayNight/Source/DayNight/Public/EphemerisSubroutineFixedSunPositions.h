#pragma once
#include "CoreMinimal.h"
#include "EphemerisSubroutine.h"
#include "EphemerisSubroutineFixedSunPositions.generated.h"

class UFixedSunPositions;

UCLASS(Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineFixedSunPositions : public UEphemerisSubroutine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFixedSunPositions* FixedPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UEphemerisSubroutineFixedSunPositions();
};

