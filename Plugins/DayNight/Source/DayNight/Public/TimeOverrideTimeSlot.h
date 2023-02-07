#pragma once
#include "CoreMinimal.h"
#include "TimeOverrideTimeOnly.h"
#include "TimeSourceSlotSetupName.h"
#include "TimeOverrideTimeSlot.generated.h"

class UTimeSourceSlotSetup;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UTimeOverrideTimeSlot : public UTimeOverrideTimeOnly {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeSourceSlotSetup* Setup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeSourceSlotSetupName Slot;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UTimeOverrideTimeSlot();
};

