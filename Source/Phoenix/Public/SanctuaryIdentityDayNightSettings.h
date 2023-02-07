#pragma once
#include "CoreMinimal.h"
#include "SanctuaryIdentityDayNightSettings.generated.h"

class UEphemerisSubroutine;
class UTimeSource;

USTRUCT(BlueprintType)
struct FSanctuaryIdentityDayNightSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTimeSource*> TimeSources;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UEphemerisSubroutine*> EphemerisProgram;
    
    PHOENIX_API FSanctuaryIdentityDayNightSettings();
};

