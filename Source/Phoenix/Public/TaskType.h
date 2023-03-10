#pragma once
#include "CoreMinimal.h"
#include "TaskType.generated.h"

UENUM(BlueprintType)
enum TaskType {
    TASK_TYPE_EVALACHIEVEMENT,
    TASK_TYPE_EVALADDBEACON,
    TASK_TYPE_EVALBLUEPRINT,
    TASK_TYPE_EVALBRANCHSTALL,
    TASK_TYPE_EVALCANADDTOINVENTORY,
    TASK_TYPE_EVALCHARACTERMOVEMENT,
    TASK_TYPE_EVALCONVERSATIONRESULT,
    TASK_TYPE_EVALCURTAINRAISED,
    TASK_TYPE_EVALDELAY,
    TASK_TYPE_EVALDELAYONCE,
    TASK_TYPE_EVALDELIVERTO,
    TASK_TYPE_EVALDELIVERTOOBJECT,
    TASK_TYPE_EVALENCOUNTERCOMPLETE,
    TASK_TYPE_EVALENTERWORLD,
    TASK_TYPE_EVALFAKETASKOBJECTIVE,
    TASK_TYPE_EVALFORCEDCONVERSATIONALLOWED,
    TASK_TYPE_EVALGAINEDKNOWLEDGE,
    TASK_TYPE_EVALGAMENOTPAUSED,
    TASK_TYPE_EVALGAMEPLATFORM,
    TASK_TYPE_EVALGEAR,
    TASK_TYPE_EVALHOUSESTATUS,
    TASK_TYPE_EVALINTERACTEDWITH,
    TASK_TYPE_EVALINTERACTEDWITHMISSIONENTRYPOINT,
    TASK_TYPE_EVALINVENTORY,
    TASK_TYPE_EVALKILLS,
    TASK_TYPE_EVALLOCK,
    TASK_TYPE_EVALLOOTDROPLOOTED,
    TASK_TYPE_EVALMISSIONACCEPTED,
    TASK_TYPE_EVALMISSIONCOMPLETE,
    TASK_TYPE_EVALMISSIONENTRYPOINTAVAILABLE,
    TASK_TYPE_EVALNAMEDCREATURESTATE,
    TASK_TYPE_EVALNEVER,
    TASK_TYPE_EVALNPCSTATE,
    TASK_TYPE_EVALONDEMANDGREETING,
    TASK_TYPE_EVALPERFORMTASKSDONE,
    TASK_TYPE_EVALPLAYERDEATH,
    TASK_TYPE_EVALPROXIMITY,
    TASK_TYPE_EVALPURCHASEDPRODUCT,
    TASK_TYPE_EVALREADMAIL,
    TASK_TYPE_EVALSPELLDIAMOND,
    TASK_TYPE_EVALSTAT,
    TASK_TYPE_EVALSTORYGRAPHEVENT,
    TASK_TYPE_EVALSYNCCONVERSATIONTIMECHANGE,
    TASK_TYPE_EVALTALKTO,
    TASK_TYPE_EVALTASKPROGRESS,
    TASK_TYPE_EVALTRIGGERANDWAITFORSTORYGRAPHEVENT,
    TASK_TYPE_EVALWAITFORSTREAMING,
    TASK_TYPE_EVALWAITFORTUTORIAL,
    TASK_TYPE_EVALWAITUNTILNEXTDAY,
    TASK_TYPE_EVALWAITUNTILTIMERANGE,
    TASK_TYPE_EVALWAKEINOWNBED,
    TASK_TYPE_ACTIVATEMISSION,
    TASK_TYPE_ACTIVATET3MOMENT,
    TASK_TYPE_ADDAMBIENTCALLOUT,
    TASK_TYPE_ADDSCHEDULEOVERRIDE,
    TASK_TYPE_ADDTOINVENTORY,
    TASK_TYPE_ADJUSTINVENTORYBYCONTAINER,
    TASK_TYPE_AGGRONPC,
    TASK_TYPE_ASSIGNSPELLTOSPELLDIAMOND,
    TASK_TYPE_AUTOSAVE,
    TASK_TYPE_BEGINEXCLUSIVE,
    TASK_TYPE_CHANGEUPDATECONVERSATION,
    TASK_TYPE_CHECKFIELDGUIDE,
    TASK_TYPE_CLEARBRANCHEVALSTEPBYNAME,
    TASK_TYPE_CLEARBRANCHEVALSTEPS,
    TASK_TYPE_CLEARRESPAWNLOCATIONOVERRIDE,
    TASK_TYPE_CLEARSEASONOVERRIDE,
    TASK_TYPE_COMPLETEMISSION,
    TASK_TYPE_COPYLOCK,
    TASK_TYPE_DISABLEMISSIONENTRYPOINT,
    TASK_TYPE_DISCOVERMISSION,
    TASK_TYPE_DONOTHING,
    TASK_TYPE_ENABLEMISSIONENTRYPOINT,
    TASK_TYPE_ENDEXCLUSIVE,
    TASK_TYPE_ENDPERFORMTASKS,
    TASK_TYPE_FADEIN,
    TASK_TYPE_FADEOUT,
    TASK_TYPE_FASTTRAVEL,
    TASK_TYPE_FORCEAUTOSAVE,
    TASK_TYPE_FORCECONVERSATION,
    TASK_TYPE_FORCEDCOMPANIONALLOWEDAREA,
    TASK_TYPE_GOTOSTEP,
    TASK_TYPE_GRANTKNOWLEDGE,
    TASK_TYPE_INITIALIZESCENERIG,
    TASK_TYPE_INITIALIZESTORYGRAPHEVENT,
    TASK_TYPE_KEEPCURTAINLOWERED,
    TASK_TYPE_KILLMISSION,
    TASK_TYPE_LOADMISSIONSUBLEVEL,
    TASK_TYPE_LOADTRANSIENTSUBLEVEL,
    TASK_TYPE_LOWERCURTAIN,
    TASK_TYPE_PAUSENOTIFICATIONCATEGORY,
    TASK_TYPE_PERFORMTASKS,
    TASK_TYPE_PLAYDIALOGUE,
    TASK_TYPE_PLAYREPEATINGSCENERIG,
    TASK_TYPE_PLAYSCENERIG,
    TASK_TYPE_PLAYT3SCENERIG,
    TASK_TYPE_PLAYTUTORIAL,
    TASK_TYPE_POSTAKEVENTBYNAME,
    TASK_TYPE_PRINTTEXT,
    TASK_TYPE_PROTECTNPC,
    TASK_TYPE_RAISECURTAIN,
    TASK_TYPE_REFRESHVENDORSTOCK,
    TASK_TYPE_REGISTERVENDORCONVERSATION,
    TASK_TYPE_REMEMBERINVENTORY,
    TASK_TYPE_REMOVEAMBIENTCALLOUT,
    TASK_TYPE_REMOVECRITICALNPC,
    TASK_TYPE_REMOVEFROMINVENTORY,
    TASK_TYPE_REMOVESCHEDULEOVERRIDE,
    TASK_TYPE_REMOVEUPDATECONVERSATION,
    TASK_TYPE_REPLACESCHEDULEOVERRIDE,
    TASK_TYPE_RESETSTORYGRAPH,
    TASK_TYPE_RESTOREINVENTORY,
    TASK_TYPE_RESUMENOTIFICATIONCATEGORY,
    TASK_TYPE_RUNSPECIALCASECODE,
    TASK_TYPE_SAVEINVENTORY,
    TASK_TYPE_SENDMAIL,
    TASK_TYPE_SENDMESSAGEFLOAT,
    TASK_TYPE_SENDMESSAGEINT,
    TASK_TYPE_SENDMESSAGENONE,
    TASK_TYPE_SENDMESSAGESTRING,
    TASK_TYPE_SETABANDONRESPAWN,
    TASK_TYPE_SETCONDITIONALREWARD,
    TASK_TYPE_SETCURRENTTIME,
    TASK_TYPE_SETDEBUGCOMPLETETELEPORT,
    TASK_TYPE_SETDIALOGUEGATEPATTERN,
    TASK_TYPE_SETDOORSTATE,
    TASK_TYPE_SETFORCEDCOMPANIONSTATUS,
    TASK_TYPE_SETGAMEFEATURE,
    TASK_TYPE_SETHOBOSCHEDULE,
    TASK_TYPE_SETLOCK,
    TASK_TYPE_SETNAMEDCREATURECANRETURNTOWILD,
    TASK_TYPE_SETNPCSTATE,
    TASK_TYPE_SETNPCWORLD,
    TASK_TYPE_SETQUESTACTIVEJOURNAL,
    TASK_TYPE_SETQUESTAVAILABLEJOURNAL,
    TASK_TYPE_SETQUESTCOMPLETEJOURNAL,
    TASK_TYPE_SETRESPAWNLOCATIONOVERRIDE,
    TASK_TYPE_SETSCHEDULE,
    TASK_TYPE_SETSEASON,
    TASK_TYPE_SETSEASONOVERRIDE,
    TASK_TYPE_SETSPELLDIAMONDSTATE,
    TASK_TYPE_SETSTAT,
    TASK_TYPE_SETSYSTEMICCOMPANIONSTATUS,
    TASK_TYPE_SETTIMEPASSES,
    TASK_TYPE_SETWEATHERSEQUENCE,
    TASK_TYPE_SHOWMISSIONCOMPLETEUI,
    TASK_TYPE_STARTBROOMRACE,
    TASK_TYPE_STOPREPEATINGSCENERIG,
    TASK_TYPE_STOPSCENERIG,
    TASK_TYPE_TRACKMISSION,
    TASK_TYPE_TRIGGERSTORYGRAPHEVENT,
    TASK_TYPE_UNLOADMISSIONSUBLEVEL,
    TASK_TYPE_UNREGISTERVENDORCONVERSATION,
    TASK_TYPE_UPDATEACHIEVEMENT,
    TASK_TYPE_MAX UMETA(Hidden),
};

