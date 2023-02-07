#pragma once
#include "CoreMinimal.h"
#include "DateTimeInput.h"
#include "TimeOverrideDateTime.h"
#include "TimeOverrideDateTimeInputRangeSceneRig.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UTimeOverrideDateTimeInputRangeSceneRig : public UTimeOverrideDateTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTimeInput StartDateTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTimeInput EndDateTime;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseEndDateTime;
    
    UTimeOverrideDateTimeInputRangeSceneRig();
};

