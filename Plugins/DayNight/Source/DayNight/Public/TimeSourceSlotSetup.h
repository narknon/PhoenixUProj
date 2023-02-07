#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DateInput.h"
#include "EphemerisDayInfo.h"
#include "TimeSourceSlotSetupTime.h"
#include "TimeSourceSlotValidTime.h"
#include "TimeSourceSlotSetup.generated.h"

UCLASS(Blueprintable)
class DAYNIGHT_API UTimeSourceSlotSetup : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateInput SlotDate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTimeSourceSlotSetupTime> SlotTimes;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEphemerisDayInfo DayInfo;
    
protected:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTimeSourceSlotValidTime> SortedDateTimes;
    
public:
    UTimeSourceSlotSetup();
};

