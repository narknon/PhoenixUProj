#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrivedDelegateDelegate.h"
#include "EEnemyAIState.h"
#include "EPathNodeSpeed.h"
#include "PathNode.generated.h"

class APathNode;

UCLASS(Blueprintable)
class APathNode : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APathNode*> m_nextArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_waitTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_threshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_arrivalTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyAIState m_nextAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_onArrivalEnablePerception;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_applyPathSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPathNodeSpeed m_selectedSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_pathSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_airPathNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_airPathSpeedMultiplyer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_perchPathNode;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FArrivedDelegate m_arrivedDelegate;
    
    APathNode();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetArrivalTimeout() const;
    
    UFUNCTION(BlueprintCallable)
    void BroadcastArrived(AActor* pActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Arrived();
    
};

