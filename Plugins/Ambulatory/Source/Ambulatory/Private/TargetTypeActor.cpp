#include "TargetTypeActor.h"

class AActor;

void UTargetTypeActor::SetTargetActor(AActor* InTargetActor) {
}

void UTargetTypeActor::SetSocketName(FName InSocketName) {
}

void UTargetTypeActor::SetActorOffset(FVector InActorOffset) {
}

AActor* UTargetTypeActor::GetTargetActor() const {
    return NULL;
}

FName UTargetTypeActor::GetSocketName() const {
    return NAME_None;
}

FVector UTargetTypeActor::GetActorOffset() const {
    return FVector{};
}

UTargetTypeActor::UTargetTypeActor() {
}

