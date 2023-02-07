#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CreatureGrowthHandler.generated.h"

UCLASS(Abstract, Blueprintable)
class ACreatureGrowthHandler : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* TargetCreatureActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* NewCreatureActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName NewCreatureTypeID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float NewCreatureScaleVariation;
    
public:
    ACreatureGrowthHandler();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TickFX(float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartFX();
    
    UFUNCTION(BlueprintCallable)
    void ShowNewCreature();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNewCreatureReady();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNewCreatureReady() const;
    
    UFUNCTION(BlueprintCallable)
    void Finish();
    
};

