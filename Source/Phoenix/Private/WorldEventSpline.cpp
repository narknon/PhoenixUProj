#include "WorldEventSpline.h"

class AActor;
class UBoxComponent;
class UPrimitiveComponent;
class USplineComponent;
class UTextRenderComponent;

void UWorldEventSpline::UnbindAllFromEvent(const FString& TriggerEventName) {
}

void UWorldEventSpline::UnbindAll() {
}

void UWorldEventSpline::Unbind(const FString& TriggerEventName, const FTriggerEvent Event) {
}

void UWorldEventSpline::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void UWorldEventSpline::FindEventsAtSplinePoint(const int32 SplinePointIndex, const TArray<FSplinePointEvents>& InSplinePointEvents, TArray<FString>& OutFoundEventNames) const {
}

void UWorldEventSpline::EnableTriggerEvents(bool Enable) {
}

void UWorldEventSpline::Construct_Implementation(const FTransform& Transform) {
}

void UWorldEventSpline::Bind(const FString& TriggerEventName, const FTriggerEvent Event) {
}

UTextRenderComponent* UWorldEventSpline::AddTextAtSplinePoint(const int32 SplinePointIndex, const TArray<FSplinePointEvents>& InSplinePointEvents, const FVector Offset, const USplineComponent* InSplineComponent) {
    return NULL;
}

UBoxComponent* UWorldEventSpline::AddBoxColliderAtSplinePoint(const int32 SplinePointIndex, const USplineComponent* InSplineComponent) {
    return NULL;
}

UWorldEventSpline::UWorldEventSpline() {
}

