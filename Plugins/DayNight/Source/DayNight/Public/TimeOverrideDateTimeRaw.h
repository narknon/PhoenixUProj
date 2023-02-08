#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimeOverrideDateTime.h"
#include "TimeOverrideDateTimeRaw.generated.h"

class UObject;
class UTimeOverrideDateTimeRaw;

UCLASS(Blueprintable, EditInlineNew)
class DAYNIGHT_API UTimeOverrideDateTimeRaw : public UTimeOverrideDateTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime DateTime;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UTimeOverrideDateTimeRaw();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    static void TimeOverrideDateTimeCreate(UObject* Owner, UTimeOverrideDateTimeRaw*& TimeOverride, FDateTime CreateDateTime, float CreatePriority, bool bCreateEnabled, bool bIsTransient);
    
};

