#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PerceptionPointAreaDelegateDelegate.h"
#include "PerceptionPointArea.generated.h"

class UShapeComponent;

UCLASS(Abstract, Blueprintable, MinimalAPI)
class APerceptionPointArea : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShapeComponent* CollisionComponent;
    
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<AActor>> EnteredList;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerceptionPointAreaDelegate OnEnter;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerceptionPointAreaDelegate OnExit;
    
    APerceptionPointArea(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetActive(bool bInActive);
    
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    bool GetActive();
    
};

