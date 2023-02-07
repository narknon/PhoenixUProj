#pragma once
#include "CoreMinimal.h"
#include "FireOnceSpellTool.h"
#include "AvadaKedavraSpellTool.generated.h"

class UCurveFloat;
class UMultiFX2_Base;

UCLASS(Blueprintable)
class AAvadaKedavraSpellTool : public AFireOnceSpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* TimeDilationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> KillCursedFX2;
    
    AAvadaKedavraSpellTool();
};

