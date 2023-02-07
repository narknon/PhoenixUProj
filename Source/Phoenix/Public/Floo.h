#pragma once
#include "CoreMinimal.h"
#include "DbEditorButtonWidget.h"
#include "DbSingleColumnInfo.h"
#include "GameFramework/Actor.h"
#include "Biped_Interact_Interface.h"
#include "Floo.generated.h"

class UBTService_AvaAITree;

UCLASS(Blueprintable)
class AFloo : public AActor, public IBiped_Interact_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo RegionId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo ForcedDestination;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnterCrouched;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnterDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbEditorButtonWidget AddButton;
    
    AFloo();
    UFUNCTION(BlueprintCallable)
    void ShowAvatar(bool bTF);
    
    UFUNCTION(BlueprintCallable)
    void SetFlooSourceAnim();
    
    UFUNCTION(BlueprintCallable)
    void SetAvailable(bool availableIn);
    
    UFUNCTION(BlueprintCallable)
    void ReturnToGameCamera();
    
    UFUNCTION(BlueprintCallable)
    void PlayerSelectedFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void PlayerExitingFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void PlayerExitedFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void PlayerEnteringFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void PlayerEnteredFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void PlayerDroppedFlooPowder(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void PlayerCanceledFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoad();
    
    UFUNCTION(BlueprintCallable)
    bool IsForcedDestination();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Interact(UBTService_AvaAITree* AvaService);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_SetAvailable(bool availableIn);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_PlayerSelectedFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_PlayerExitingFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_PlayerExitedFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_PlayerEnteringFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_PlayerEnteredFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_PlayerDroppedFlooPowder(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_PlayerCanceledFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_ActivateExitCamera();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_ActivateEnterCamera();
    
    UFUNCTION(BlueprintCallable)
    FString GetFlooName();
    
    UFUNCTION(BlueprintCallable)
    bool GetAvailable();
    
    UFUNCTION(BlueprintCallable)
    void ActivateExitCamera();
    
    UFUNCTION(BlueprintCallable)
    void ActivateEnterCamera();
    
    
    // Fix for true pure virtual functions not being implemented
};

