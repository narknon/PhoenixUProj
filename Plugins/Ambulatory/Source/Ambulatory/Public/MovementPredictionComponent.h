#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "EMovementSensorType.h"
#include "MovementEventData.h"
#include "MovementPredictionSettings.h"
#include "MovementSensorInfo.h"
#include "MovementPredictionComponent.generated.h"

class UMotionTable;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class AMBULATORY_API UMovementPredictionComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovementPredictionSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMotionTable* MotionTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableEventMatching;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EMovementSensorType, FMovementEventData> MovementEventData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MovementWarpingStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SteeringCorrectionStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve SteeringCorrectionWeightOverTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve FlightSteeringYawCorrectionWeightOverTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve FlightSteeringPitchCorrectionWeightOverTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugDrawMotionEvents;
    
    UMovementPredictionComponent();
    UFUNCTION(BlueprintCallable)
    void TriggerMovementEvent(EMovementSensorType InType);
    
    UFUNCTION(BlueprintCallable)
    void SetMovementState(FName InState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLastEventFollowThroughComplete() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTimeToEventTransition(FName InEventName, float& OutTimeUntilTransition) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSteeringCorrectionAngle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetPredictedUncorrectedTransform(const float InTimeFromNow) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetPredictedTransform(const float InTimeFromNow) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetNextSensorInfoOfTypes(const TArray<EMovementSensorType>& SensorTypes, float InTimeFromNow, FMovementSensorInfo& OutSensorInfo) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetNextSensorInfo(EMovementSensorType SensorType, float InTimeFromNow, FMovementSensorInfo& OutSensorInfo) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetNextBlockingCollision(float InGlancingAngleThresholdDegrees, FMovementSensorInfo& OutSensorInfo) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetMovementState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMovementEventTarget(EMovementSensorType& OutType, float& OutTimeToEvent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMovementAnimTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetFlightSteeringCorrectionAngles(const FRotator& InInputRotation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetEventFollowThroughAnimTime(FName InEventName, FName InCurrentState, float& OutAnimTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetEventAnimTime(FName InEventName, FName InCurrentState, float& OutAnimTime) const;
    
};

