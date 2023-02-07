#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Ambulatory_MobilityMode.h"
#include "EMobilityModeState.h"
#include "Ambulatory_Data.generated.h"

class UCurveFloat;

UCLASS(Blueprintable)
class AMBULATORY_API UAmbulatory_Data : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* IdleTurnAssistCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* TurnAssistCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* SpeedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* PlayRateCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CPS2SpeedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TEnumAsByte<EMobilityModeState::Type>, FAmbulatory_MobilityMode> MobilityModes;
    
    UAmbulatory_Data();
};

