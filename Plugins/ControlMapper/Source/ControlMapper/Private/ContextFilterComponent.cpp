#include "ContextFilterComponent.h"

class AActor;

void UContextFilterComponent::SetContextOnActor(AActor* InActor, const FInputContextWithType Context, bool bFlag) {
}

void UContextFilterComponent::SetContext(const FInputContextWithType Context, bool bFlag) {
}

void UContextFilterComponent::RemoveFilter(const FInputFilter& InFilter) {
}

bool UContextFilterComponent::GetContextOnActor(AActor* InActor, const FInputContextWithType Context) {
    return false;
}

bool UContextFilterComponent::GetContext(const FInputContextWithType Context) {
    return false;
}

bool UContextFilterComponent::EvaluateFilterOnActor(AActor* InActor, const FInputFilter InputFilter) {
    return false;
}

bool UContextFilterComponent::EvaluateFilter(const FInputFilter& InFilter) {
    return false;
}

void UContextFilterComponent::ClearContextOnActor(AActor* InActor, const FInputContextWithType Context) {
}

void UContextFilterComponent::ClearContext(const FInputContextWithType Context) {
}

void UContextFilterComponent::AddFilter(const FInputFilter& InFilter) {
}

UContextFilterComponent::UContextFilterComponent() {
}

