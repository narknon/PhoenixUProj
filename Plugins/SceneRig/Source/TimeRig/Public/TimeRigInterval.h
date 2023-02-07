#pragma once
#include "CoreMinimal.h"
#include "TimeRigCoordinate.h"
#include "TimeRigElement.h"
#include "TimeRigInputSymbol.h"
#include "TimeRigOutputSymbol.h"
#include "TimeRigInterval.generated.h"

class UTimeRigElementState;
class UTimeRigInstanceContext;

UCLASS(Blueprintable)
class TIMERIG_API UTimeRigInterval : public UTimeRigElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigInputSymbol Start;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigOutputSymbol Finish;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SortOrder;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UsePostActorTick;
    
    UTimeRigInterval();
    UFUNCTION(BlueprintCallable)
    void OnStartChanged(FTimeRigCoordinate Previous, FTimeRigCoordinate Current, UTimeRigInstanceContext* Context, UTimeRigElementState* State);
    
    UFUNCTION(BlueprintCallable)
    void OnFinishChanged(FTimeRigCoordinate Previous, FTimeRigCoordinate Current, UTimeRigInstanceContext* Context, UTimeRigElementState* State);
    
};

