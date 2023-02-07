#include "MastermindBPLibrary.h"

class UMastermindJsonObject;
class UObject;

void UMastermindBPLibrary::SimulateTappedInput(const UObject* InWorldContextObject, FKey InInputKey) {
}

void UMastermindBPLibrary::SimulateInput(const UObject* InWorldContextObject, FKey InInputKey, EInputEvent InInputEvent) {
}

void UMastermindBPLibrary::SimulateAxis(const UObject* InWorldContextObject, FKey InInputKey, float InDelta) {
}

void UMastermindBPLibrary::MastermindSendTestResults(const UObject* InWorldContextObject, const TArray<FMastermindTestResult>& InTestResults) {
}

void UMastermindBPLibrary::MastermindSendTestResultMessage(const UObject* InWorldContextObject, const FMastermindTestResultMessage& InResult) {
}

void UMastermindBPLibrary::MastermindSendTestResult(const UObject* InWorldContextObject, const FString& InName, bool bInIsSuccess) {
}

void UMastermindBPLibrary::MastermindSendStepResult(const UObject* InWorldContextObject, const FString& InMessage, bool bInIsSuccess, ETestSuccess InTestSuccess, const TArray<FString>& InArtifacts, const UMastermindJsonObject* InData) {
}

void UMastermindBPLibrary::MastermindSendProgressUpdateMessage(const UObject* InWorldContextObject, const FMastermindProgressUpdate& InUpdate) {
}

void UMastermindBPLibrary::MastermindSendProgressUpdate(const UObject* InWorldContextObject, const FString& InMessage) {
}

void UMastermindBPLibrary::MastermindSendCommandResultMessage(const UObject* InWorldContextObject, const FMastermindCommandResult& InResult) {
}

FMastermindTestResult UMastermindBPLibrary::CreateMastermindTestResult(const UObject* InWorldContextObject, const FString& InName, bool bInIsSuccess) {
    return FMastermindTestResult{};
}

FMastermindProgressUpdate UMastermindBPLibrary::CreateMastermindProgressUpdate(const UObject* InWorldContextObject, const FString& InMessage) {
    return FMastermindProgressUpdate{};
}

FMastermindCommandResult UMastermindBPLibrary::CreateMastermindCommandResult(const UObject* InWorldContextObject, const FString& InMessage, bool bInIsSuccess, ETestSuccess InTestSuccess, const TArray<FString>& InArtifacts, const UMastermindJsonObject* InData) {
    return FMastermindCommandResult{};
}

UMastermindBPLibrary::UMastermindBPLibrary() {
}

