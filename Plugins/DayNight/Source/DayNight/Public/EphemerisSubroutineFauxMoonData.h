#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EphemerisDayInfo.h"
#include "EphemerisSubroutineFauxMoonData.generated.h"

UCLASS(Blueprintable, Transient)
class DAYNIGHT_API UEphemerisSubroutineFauxMoonData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEphemerisDayInfo IdealDayInfo;
    
    UEphemerisSubroutineFauxMoonData();
};

