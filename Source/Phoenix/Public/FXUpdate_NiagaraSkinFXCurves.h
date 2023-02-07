#pragma once
#include "CoreMinimal.h"
#include "FXUpdate_Tick.h"
#include "Templates/SubclassOf.h"
#include "UpdateNiagaraSkinFXColorCurve.h"
#include "UpdateNiagaraSkinFXFloatCurve.h"
#include "FXUpdate_NiagaraSkinFXCurves.generated.h"

class ASkinFXDefinition;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_NiagaraSkinFXCurves : public UFXUpdate_Tick {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FUpdateNiagaraSkinFXFloatCurve> FloatCurves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FUpdateNiagaraSkinFXColorCurve> ColorCurves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> SkinFX;
    
    UFXUpdate_NiagaraSkinFXCurves();
};

