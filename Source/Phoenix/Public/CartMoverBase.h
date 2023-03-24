#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "CartSetup.h"
#include "OnCartReachedEndOfSplineDelegate.h"
#include "WorldEventActor.h"
#include "CartMoverBase.generated.h"

class AActor;
class UPrimitiveComponent;
class USplineComponent;
class UTimelineComponent;

UCLASS(Blueprintable)
class ACartMoverBase : public AWorldEventActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCartReachedEndOfSpline OnCartReachedEndOfSpline;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCartStopping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwingLimiter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwingAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle RestartTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTimelineComponent* TailGateTimeline;
    
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> SlowingSocialAgents;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> BlockingSocialAgents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USplineComponent> Spline;
    
public:
    ACartMoverBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetMaxSpeed(const float InMaxSpeed);
    
    UFUNCTION(BlueprintCallable)
    void ResumeMovement();
    
    UFUNCTION(BlueprintCallable)
    void PauseMovement();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnStopBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnStopBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnSlowDownBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnSlowDownBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnDetectedEnemyDeath(AActor* EnemyAI);
    
protected:
    UFUNCTION(BlueprintCallable)
    void MoveAlongSpline(UPARAM(Ref) FCartSetup& InCartSetup, float DeltaTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCharacter(const AActor* ObstructingActor) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsCartBlocking(const AActor* ObstructingActor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasStopped() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasReachedEndOfSpline() const;
    
    UFUNCTION(BlueprintCallable)
    void BeginMovement(UPARAM(Ref) FCartSetup& InCartSetup, bool bStartFromBeginning);
    
};

