#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ESignificanceBiasEnum.h"
#include "PhoenixSignificanceManager.generated.h"

class AActor;
class UBudgeter;
class UPhoenixSignificanceManager;

UCLASS(Blueprintable)
class PHOENIXSIGNIFICANCEMANAGER_API UPhoenixSignificanceManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UBudgeter*> Budgeters;
    
public:
    UPhoenixSignificanceManager();
    UFUNCTION(BlueprintCallable)
    bool SetObjectSignficanceBias(const UObject* Object, ESignificanceBiasEnum SignificanceBias);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRegisteredActorDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UPhoenixSignificanceManager* GetSignificanceManager(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSignificance(const UObject* Object) const;
    
};

