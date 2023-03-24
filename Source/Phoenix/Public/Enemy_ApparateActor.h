#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ArrivedEventDelegate.h"
#include "DoneEventDelegate.h"
#include "Enemy_ApparateActorData.h"
#include "Enemy_ApparateActor.generated.h"

UCLASS(Blueprintable)
class AEnemy_ApparateActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_ApparateActorData Data;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bArrived;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FArrivedEvent ArrivedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDoneEvent DoneEvent;
    
    AEnemy_ApparateActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasArrived() const;
    
    UFUNCTION(BlueprintCallable)
    void BroadcastDone(AActor* pActor);
    
    UFUNCTION(BlueprintCallable)
    void BroadcastArrived(AActor* pActor, FVector Loc);
    
};

