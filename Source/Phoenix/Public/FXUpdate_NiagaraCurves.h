#pragma once
#include "CoreMinimal.h"
#include "FXUpdate_Tick.h"
#include "UpdateNiagaraFXColorCurve.h"
#include "UpdateNiagaraFXFloatCurve.h"
#include "FXUpdate_NiagaraCurves.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_NiagaraCurves : public UFXUpdate_Tick {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FUpdateNiagaraFXFloatCurve> FloatCurves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FUpdateNiagaraFXColorCurve> ColorCurves;
    
    UFXUpdate_NiagaraCurves();
};

