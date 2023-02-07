#pragma once
#include "CoreMinimal.h"
#include "EWInstrumentedProfilerAutomatedResumeSettings.generated.h"

UENUM()
enum class EWInstrumentedProfilerAutomatedResumeSettings : int32 {
    Never,
    FirstFrame,
    Start,
    StartProgram,
    LoadingPhasePostConfigInit,
    LoadingPhasePreDefault,
    LoadingPhaseDefault,
    LoadingPhasePostDefault,
    LoadingPhasePreLoadingScreen,
    LoadingPhasePostEngineInit,
};

