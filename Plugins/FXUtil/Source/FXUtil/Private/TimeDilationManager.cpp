#include "TimeDilationManager.h"

class AActor;
class UCurveFloat;
class UObject;

void UTimeDilationManager::StartWorldTimeDilation(const UObject* WorldContextObject, float Dilation, const UObject* Provider, float EaseInDuration) {
}

void UTimeDilationManager::StartActorTimeDilation(AActor* Actor, float Dilation, const UObject* Provider, float EaseInDuration) {
}

void UTimeDilationManager::StartActorTimeAcceleration(AActor* Actor, float AccelerationDilation, float AcceleratedDuration, const UObject* Provider) {
}

void UTimeDilationManager::StartActorCounterDilation(AActor* Actor) {
}

void UTimeDilationManager::PlayWorldTimeDilationEffect(const UObject* WorldContextObject, UCurveFloat* TimeDilationCurve) {
}

void UTimeDilationManager::PlayActorTimeDilationEffect(AActor* Actor, UCurveFloat* TimeDilationCurve) {
}

void UTimeDilationManager::FinishWorldTimeDilation(const UObject* Provider, float EaseOutDuration) {
}

void UTimeDilationManager::FinishActorTimeDilation(const UObject* Provider, float EaseOutDuration) {
}

void UTimeDilationManager::FinishActorCounterDilation(AActor* Actor) {
}

UTimeDilationManager::UTimeDilationManager() {
}

