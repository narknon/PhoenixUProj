#pragma once
#include "CoreMinimal.h"
#include "ETimeOverrideType.h"
#include "TimeOverrideTimeOnly.h"
#include "TimeOverrideTimeHours.generated.h"

class UObject;
class UTimeOverrideTimeHours;

UCLASS(Blueprintable, EditInlineNew)
class DAYNIGHT_API UTimeOverrideTimeHours : public UTimeOverrideTimeOnly {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Time;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeOverrideType Type;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UTimeOverrideTimeHours();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    static void TimeOverrideTimeHoursCreate(UObject* Owner, UTimeOverrideTimeHours*& TimeOverride, float CreateTime, ETimeOverrideType CreateType, float CreatePriority, bool bCreateEnabled, bool bIsTransient);
    
};

