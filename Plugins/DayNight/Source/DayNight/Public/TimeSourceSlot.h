#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EDateTimeDayOfWeek.h"
#include "TimeSourceLocal.h"
#include "TimeSourceSlotSetupName.h"
#include "TimeSourceSlot.generated.h"

class UTimeSourceSlotSetup;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UTimeSourceSlot : public UTimeSourceLocal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeSourceSlotSetup* Setup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeSourceSlotSetupName Slot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDateTimeDayOfWeek DayOfWeek;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Rate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseRate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDateTime QuantizedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float SlotRate;
    
public:
    UTimeSourceSlot();
    UFUNCTION(BlueprintCallable)
    void EditorForceUpdate();
    
};

