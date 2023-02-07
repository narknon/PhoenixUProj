#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EInteractiveAction.h"
#include "EInteractiveState.h"
#include "InteractiveObjectLinkData.h"
#include "InteractiveObjectComponent.generated.h"

class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInteractiveObjectComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInteractiveState m_initialState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EInteractiveState> m_stateArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInteractiveObjectLinkData> m_linkArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCustomInteract;
    
    UInteractiveObjectComponent();
    UFUNCTION(BlueprintCallable)
    void SetState(EInteractiveState State);
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void HandleInteract(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable)
    EInteractiveState GetState();
    
    UFUNCTION(BlueprintCallable)
    bool GetEnabled();
    
    UFUNCTION(BlueprintCallable)
    void CheckForStateChange(EInteractiveAction Action);
    
};

