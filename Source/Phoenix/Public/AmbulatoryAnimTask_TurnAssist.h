#pragma once
#include "CoreMinimal.h"
#include "AmbulatoryTurnAssistAnimTask.h"
#include "UObject/NoExportTypes.h"
#include "AlphaBlend.h"
#include "AmbulatoryAnimTask_TurnAssist.generated.h"

UCLASS(Blueprintable)
class UAmbulatoryAnimTask_TurnAssist : public UAmbulatoryTurnAssistAnimTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAlphaBlend TurningBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector CurrentDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector DesiredDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bTimerReset;
    
public:
    UAmbulatoryAnimTask_TurnAssist();
};

