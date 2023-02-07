#pragma once
#include "CoreMinimal.h"
#include "DateInput.h"
#include "Templates/SubclassOf.h"
#include "TimeSourceVolume.h"
#include "TimeSourceScrubbable.generated.h"

class UTimeSourceScrubbableControlBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UTimeSourceScrubbable : public UTimeSourceVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateInput BaseDate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTimeSourceScrubbableControlBase* Control;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTimeSourceScrubbableControlBase> ControlClass;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UTimeSourceScrubbable();
};

