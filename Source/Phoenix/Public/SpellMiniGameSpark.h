#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PhoenixUserWidget.h"
#include "SpellUnlockMiniGamePathSegment.h"
#include "SpellMiniGameSpark.generated.h"

class UObject;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API USpellMiniGameSpark : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsRunning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D LinearInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAcceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoostMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoostTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoostRampUpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoostRampDownSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OrientationSmoothSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxOrientationSmoothAngle;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NormalizedPerformanceSpeed;
    
public:
    USpellMiniGameSpark();
    UFUNCTION(BlueprintCallable)
    void Stop();
    
    UFUNCTION(BlueprintCallable)
    void Start();
    
    UFUNCTION(BlueprintCallable)
    void Reset();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRun();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReset();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputFailure();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFail(const UObject* sender);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnterInputWindow();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBoostStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBoostEnd();
    
public:
    UFUNCTION(BlueprintCallable)
    void LogSpellMinigameData(const FString& LogData);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetVelocity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalDistanceAsPercent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetOrientation() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetNextAngleTowardsDirection(float CurrentAngle, const FVector2D& TargetDirection, const float& SmoothSpeed, const float& MaxSmoothAngle) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsBoosting() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDistanceAlongPathSegment(const FSpellUnlockMiniGamePathSegment PathSegment) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetDirection() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetCurrentPositionOnPath() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentPathSegmentIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSpellUnlockMiniGamePathSegment GetCurrentPathSegment() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentDistanceAlongPath() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetActiveSpeedScale() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void ApplyBoost();
    
};

