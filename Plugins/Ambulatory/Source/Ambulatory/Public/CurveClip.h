#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Curves/CurveBase.h"
#include "Curves/RichCurve.h"
#include "EFootPlantEnum.h"
#include "CurveClip.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class UCurveClip : public UCurveBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRichCurve TimeToPhaseCurve;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRichCurve PhaseToTimeCurve;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRichCurve FootPlantsCurve;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRichCurve VelocityCurves[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRichCurve AccelerationCurves[3];
    
    UCurveClip();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetVelocity(float InTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EFootPlantEnum GetFootPlants(float InTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetAcceleration(float InTime) const;
    
};

