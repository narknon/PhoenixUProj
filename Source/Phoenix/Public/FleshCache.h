#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CharacterShutdownProvider_Interface.h"
#include "OnFleshCreatedDelegate.h"
#include "OnFleshDestroyedDelegate.h"
#include "OnGetFleshDelegate.h"
#include "FleshCache.generated.h"

class AActor;
class UActorComponent;
class UFleshCache;

UCLASS(Blueprintable)
class PHOENIX_API UFleshCache : public UObject, public ICharacterShutdownProvider_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFleshCreated OnFleshCreated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFleshDestroyed OnFleshDestroyed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGetFlesh OnGetFlesh;
    
    UFleshCache();
private:
    UFUNCTION(BlueprintCallable)
    void OnPreCacheFinished(AActor* InOwner);
    
    UFUNCTION(BlueprintCallable)
    void OnComponentActivated(UActorComponent* InComponent, bool InSuccess);
    
    UFUNCTION(BlueprintCallable)
    void HandleFastTravelFinished(const UObject* InCaller);
    
    UFUNCTION(BlueprintCallable)
    void HandleFastTravelBegun(const UObject* InCaller);
    
public:
    UFUNCTION(BlueprintCallable)
    static UFleshCache* Get();
    
    
    // Fix for true pure virtual functions not being implemented
};

