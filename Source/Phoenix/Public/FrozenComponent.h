#pragma once
#include "CoreMinimal.h"
#include "FrozenData.h"
#include "StateEffectComponent.h"
#include "FrozenComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFrozenComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartFrozen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialDuration;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FFrozenData FrozenData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> FrozenActors;
    
public:
    UFrozenComponent();
private:
    UFUNCTION(BlueprintCallable)
    void SetupDelegate();
    
public:
    UFUNCTION(BlueprintCallable)
    bool RemoveFrozenActor(AActor* OutFrozenActor);
    
    UFUNCTION(BlueprintCallable)
    void OnBroken(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void ClearFrozenActors();
    
    UFUNCTION(BlueprintCallable)
    void AddToInstanceList(AActor* InInstigator, int32 InMaxObjectInstancesPerInstigator, int32 InMaxCharacterInstancesPerInstigator);
    
    UFUNCTION(BlueprintCallable)
    void AddFrozenActor(AActor* InFrozenActor);
    
};

