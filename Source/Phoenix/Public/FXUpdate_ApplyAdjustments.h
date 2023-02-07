#pragma once
#include "CoreMinimal.h"
#include "FXUpdate_Tick.h"
#include "FXUpdate_ApplyAdjustments.generated.h"

class UFXAdjustments;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_ApplyAdjustments : public UFXUpdate_Tick {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseFXAsSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXAdjustments*> Adjustments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeactivateIfAdjustmentsFail;
    
public:
    UFXUpdate_ApplyAdjustments();
};

