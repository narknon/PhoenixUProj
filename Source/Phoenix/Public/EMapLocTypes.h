#pragma once
#include "CoreMinimal.h"
#include "EMapLocTypes.generated.h"

UENUM(BlueprintType)
namespace EMapLocTypes {
    enum Type {
        MAP_LOC_KEY_NONE,
        MAP_LOC_KEY_ZOOM,
        MAP_LOC_KEY_NEXT_MAP,
        MAP_LOC_KEY_TRACK_QUEST,
        MAP_LOC_KEY_UNTRACK_QUEST,
        MAP_LOC_KEY_SET_WAYPOINT,
        MAP_LOC_KEY_UNSET_WAYPOINT,
        MAP_LOC_KEY_TRAVEL,
        MAP_LOC_KEY_TRAVEL_CLOSEST,
        MAP_LOC_KEY_BACK,
        MAP_LOC_KEY_SELECT,
        MAP_LOC_KEY_MOVE_CAMERA,
        MAP_LOC_KEY_FILTER,
        MAP_LOC_KEY_ROTATE,
        MAP_LOC_GOTO_QUEST_LOG,
        MAP_LOC_GOTO_QUEST_LOG_MNK,
        MAP_LOC_KEY_FAST_TRAVEL_LIST_DO_FAST_TRAVEL,
        MAP_LOC_KEY_FAST_TRAVEL_LIST_DO_SELECT_REGION,
        MAP_LOC_KEY_WAIT,
        MAP_LOC_KEY_TRAVEL_MOUSE_KBD,
        MAP_LOC_KEY_ROTATE_MOUSE_KBD,
        MAP_LOC_KEY_FAST_TRAVEL_LIST_DO_FAST_TRAVEL_MOUSE_KBD,
        MAP_LOC_MAX UMETA(Hidden),
    };
}

