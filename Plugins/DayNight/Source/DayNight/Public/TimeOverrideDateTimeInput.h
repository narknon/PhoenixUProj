#pragma once
#include "CoreMinimal.h"
#include "DateTimeInput.h"
#include "TimeOverrideDateTime.h"
#include "TimeOverrideDateTimeInput.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class DAYNIGHT_API UTimeOverrideDateTimeInput : public UTimeOverrideDateTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTimeInput DateTime;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UTimeOverrideDateTimeInput();
};

