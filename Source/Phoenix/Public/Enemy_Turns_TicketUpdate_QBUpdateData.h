#pragma once
#include "CoreMinimal.h"
#include "Enemy_QBUpdateData.h"
#include "Enemy_Turns_TicketUpdate_QBUpdateData.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, EditInlineNew)
class UEnemy_Turns_TicketUpdate_QBUpdateData : public UEnemy_QBUpdateData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* SinceLastAttackedCountCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* OffScreenTimeCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomScoreMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomScoreMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomScoreTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomScoreTimeoutDeviation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargettedScore;
    
    UEnemy_Turns_TicketUpdate_QBUpdateData();
};

