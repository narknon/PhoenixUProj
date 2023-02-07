#pragma once
#include "CoreMinimal.h"
#include "EWInstrumentedProfilerCategorySettings.generated.h"

UENUM()
enum class EWInstrumentedProfilerCategorySettings : uint32 {
    NotSelected,
    Always,
    Able,
    Actor,
    AI,
    Anim,
    AsyncTask,
    Audio,
    AvaAnimation,
    Blueprint,
    Character,
    Collision,
    CoreEngine,
    FileIO,
    Gameplay,
    GC,
    IK,
    ImGui,
    Missions,
    Modules,
    MovementComponent,
    Navigation,
    Network,
    Physics,
    Player,
    PSO,
    Rendering,
    Stall,
    Streaming,
    TaskGraph,
    TickFunction,
    UI,
    UnrealLogs,
    UnrealStats,
    VFX,
};

