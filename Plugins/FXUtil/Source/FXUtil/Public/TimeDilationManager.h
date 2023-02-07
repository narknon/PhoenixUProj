#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActiveTimeDilationEffectGroup.h"
#include "TimeDilationManager.generated.h"

class AActor;
class UCurveFloat;
class UWorld;

UCLASS(Blueprintable)
class FXUTIL_API UTimeDilationManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UWorld>, FActiveTimeDilationEffectGroup> ActiveWorldEffects;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FActiveTimeDilationEffectGroup> ActiveActorEffects;
    
public:
    UTimeDilationManager();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void StartWorldTimeDilation(const UObject* WorldContextObject, float Dilation, const UObject* Provider, float EaseInDuration);
    
    UFUNCTION(BlueprintCallable)
    static void StartActorTimeDilation(AActor* Actor, float Dilation, const UObject* Provider, float EaseInDuration);
    
    UFUNCTION(BlueprintCallable)
    static void StartActorTimeAcceleration(AActor* Actor, float AccelerationDilation, float AcceleratedDuration, const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    static void StartActorCounterDilation(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PlayWorldTimeDilationEffect(const UObject* WorldContextObject, UCurveFloat* TimeDilationCurve);
    
    UFUNCTION(BlueprintCallable)
    static void PlayActorTimeDilationEffect(AActor* Actor, UCurveFloat* TimeDilationCurve);
    
    UFUNCTION(BlueprintCallable)
    static void FinishWorldTimeDilation(const UObject* Provider, float EaseOutDuration);
    
    UFUNCTION(BlueprintCallable)
    static void FinishActorTimeDilation(const UObject* Provider, float EaseOutDuration);
    
    UFUNCTION(BlueprintCallable)
    static void FinishActorCounterDilation(AActor* Actor);
    
};

