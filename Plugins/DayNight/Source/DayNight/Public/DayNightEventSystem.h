#pragma once
#include "CoreMinimal.h"
#include "DayNightEventSystemLastState.h"
#include "DayNightEventsCurrentState.h"
#include "DayNightGlobalEvents.h"
#include "DayNightReceiverEvents.h"
#include "DayNightEventSystem.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct DAYNIGHT_API FDayNightEventSystem {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UObject>, FDayNightReceiverEvents> EventMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FDayNightEventSystemLastState> LastStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FDayNightGlobalEvents> GlobalEventMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDayNightEventSystemLastState GlobalLastState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDayNightEventsCurrentState GlobalCurrentState;
    
    FDayNightEventSystem();
};

