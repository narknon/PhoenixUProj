#include "MastermindActorComponent.h"

class APlayerController;

FMastermindCommandResult UMastermindActorComponent::TeleportPlayerPawn_Implementation(float InX, float InY, float InZ) {
    return FMastermindCommandResult{};
}

void UMastermindActorComponent::ServerTeleport_Implementation(float InX, float InY, float InZ) {
}
bool UMastermindActorComponent::ServerTeleport_Validate(float InX, float InY, float InZ) {
    return true;
}

void UMastermindActorComponent::ServerLookInDirection_Implementation(float InPitch, float InYaw, float InRoll) {
}
bool UMastermindActorComponent::ServerLookInDirection_Validate(float InPitch, float InYaw, float InRoll) {
    return true;
}

void UMastermindActorComponent::SendMastermindMessage(const FMastermindCommandResult& InMastermindMessage) {
}

void UMastermindActorComponent::QATeleport(float InX, float InY, float InZ) {
}

void UMastermindActorComponent::QALookInDirection(float InPitch, float InYaw, float InRoll) {
}

FMastermindCommandResult UMastermindActorComponent::NativeTeleportPlayerPawn(float InX, float InY, float InZ) {
    return FMastermindCommandResult{};
}

FMastermindCommandResult UMastermindActorComponent::NativeLookInDirection(float InPitch, float InYaw, float InRoll) {
    return FMastermindCommandResult{};
}

FMastermindCommandResult UMastermindActorComponent::LookInDirection_Implementation(float InPitch, float InYaw, float InRoll) {
    return FMastermindCommandResult{};
}

APlayerController* UMastermindActorComponent::GetOwniningPlayerController() const {
    return NULL;
}

void UMastermindActorComponent::ClientSendMastermindMessage_Implementation(const FMastermindCommandResult& InMastermindMessage) {
}
bool UMastermindActorComponent::ClientSendMastermindMessage_Validate(const FMastermindCommandResult& InMastermindMessage) {
    return true;
}

UMastermindActorComponent::UMastermindActorComponent() {
}

