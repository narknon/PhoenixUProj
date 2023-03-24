#pragma once
#include "CoreMinimal.h"
#include "PerceptionPoint.h"
#include "Enemy_PerceptionPoint.generated.h"

class APerceptionPointArea;

UCLASS(Blueprintable)
class AEnemy_PerceptionPoint : public APerceptionPoint {
    GENERATED_BODY()
public:
    AEnemy_PerceptionPoint(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RemovePerceiveVolume(APerceptionPointArea* InAreaPtr);
    
    UFUNCTION(BlueprintCallable)
    void RemoveLoseVolume(APerceptionPointArea* InAreaPtr);
    
    UFUNCTION(BlueprintCallable)
    void RemoveForceVolume(APerceptionPointArea* InAreaPtr);
    
    UFUNCTION(BlueprintCallable)
    void RemoveExcludeVolume(APerceptionPointArea* InAreaPtr);
    
    UFUNCTION(BlueprintCallable)
    void AddPerceiveVolume(APerceptionPointArea* InAreaPtr);
    
    UFUNCTION(BlueprintCallable)
    void AddLoseVolume(APerceptionPointArea* InAreaPtr);
    
    UFUNCTION(BlueprintCallable)
    void AddForceVolume(APerceptionPointArea* InAreaPtr);
    
    UFUNCTION(BlueprintCallable)
    void AddExcludeVolume(APerceptionPointArea* InAreaPtr);
    
};

