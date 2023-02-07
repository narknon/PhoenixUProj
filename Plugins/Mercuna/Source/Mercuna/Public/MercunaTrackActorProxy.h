#pragma once
#include "CoreMinimal.h"
#include "AITypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "EMercunaMoveResult.h"
#include "MercunaNavigationResultDelegate.h"
#include "MercunaTrackActorProxy.generated.h"

class AActor;
class APawn;
class UMercunaTrackActorProxy;
class UObject;

UCLASS(Blueprintable, MinimalAPI)
class UMercunaTrackActorProxy : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaNavigationResult OnFailure;
    
    UMercunaTrackActorProxy();
private:
    UFUNCTION(BlueprintCallable)
    void OnMoveComplete(FAIRequestID RequestID, TEnumAsByte<EMercunaMoveResult::Type> Result);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UMercunaTrackActorProxy* MercunaTrackActor(UObject* WorldContextObject, APawn* Pawn, AActor* Actor, float Distance, float Speed);
    
};

