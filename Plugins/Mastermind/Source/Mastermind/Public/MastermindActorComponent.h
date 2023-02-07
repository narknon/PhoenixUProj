#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MastermindCommandResult.h"
#include "MastermindActorComponent.generated.h"

class APlayerController;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MASTERMIND_API UMastermindActorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UMastermindActorComponent();
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FMastermindCommandResult TeleportPlayerPawn(float InX, float InY, float InZ);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerTeleport(float InX, float InY, float InZ);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerLookInDirection(float InPitch, float InYaw, float InRoll);
    
    UFUNCTION(BlueprintCallable)
    static void SendMastermindMessage(const FMastermindCommandResult& InMastermindMessage);
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void QATeleport(float InX, float InY, float InZ);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QALookInDirection(float InPitch, float InYaw, float InRoll);
    
protected:
    UFUNCTION(BlueprintCallable)
    FMastermindCommandResult NativeTeleportPlayerPawn(float InX, float InY, float InZ);
    
    UFUNCTION(BlueprintCallable)
    FMastermindCommandResult NativeLookInDirection(float InPitch, float InYaw, float InRoll);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FMastermindCommandResult LookInDirection(float InPitch, float InYaw, float InRoll);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayerController* GetOwniningPlayerController() const;
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientSendMastermindMessage(const FMastermindCommandResult& InMastermindMessage);
    
};

