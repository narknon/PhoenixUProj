#pragma once
#include "CoreMinimal.h"
#include "FXUpdate_Tick.h"
#include "FXUpdate_BeamTargetAttach.generated.h"

class UMultiFX2_BeamTargetBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_BeamTargetAttach : public UFXUpdate_Tick {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NoClear, meta=(AllowPrivateAccess=true))
    UMultiFX2_BeamTargetBase* TargetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpolationWeight;
    
public:
    UFXUpdate_BeamTargetAttach();
};

