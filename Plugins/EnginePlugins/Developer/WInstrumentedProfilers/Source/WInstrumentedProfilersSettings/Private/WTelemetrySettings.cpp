#include "WTelemetrySettings.h"

UWTelemetrySettings::UWTelemetrySettings() {
    this->AutomatedResume = EWInstrumentedProfilerAutomatedResumeSettings::Start;
    this->bEnableTelemetry = false;
    this->TelemetrySizeInKB = 131072;
    this->ConnectionAddress = TEXT("localhost");
    this->bBreakOnMismatchedZone = false;
    this->TelemetryMaxThreadCount = 96;
    this->TelemetryMaxTimeSpanTrackCount = 16;
    this->bEnableContextSwitches = false;
    this->bEnableMessages = true;
    this->bEnableOutputDebugInfo = true;
    this->bBreakOnWarning = false;
}

