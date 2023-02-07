#pragma once
#include "CoreMinimal.h"
#include "EDayNightReportGeneral.generated.h"

UENUM(BlueprintType)
enum class EDayNightReportGeneral : uint8 {
    DateTime,
    Time,
    NormalizedTime,
    ProbeLerp,
    ProbeIndex,
    BlendDomainIndoors,
    BlendDomainDayNight,
    BlendDomainOvercast,
    Eye,
    GlobalSS,
};

