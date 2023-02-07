#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "AIPerformTaskBase.h"
#include "EPerformTaskSpeedMode.h"
#include "AIPerformTaskMoveToStation.generated.h"

class AStation;
class UObject;

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskMoveToStation : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AStation* TargetStation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo ActivityType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInteract;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ConnectionIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float stationDuration;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTaskSpeedMode SpeedMode;
    
public:
    UAIPerformTaskMoveToStation();
protected:
    UFUNCTION(BlueprintCallable)
    void StartStationExit();
    
    UFUNCTION(BlueprintCallable)
    void OnStationEnterFinished(const UObject* i_caller);
    
};

