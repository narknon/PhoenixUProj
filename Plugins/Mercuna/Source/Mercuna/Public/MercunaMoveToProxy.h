#pragma once
#include "CoreMinimal.h"
#include "AITypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "EMercunaMoveResult.h"
#include "MercunaNavigationResultDelegate.h"
#include "MercunaMoveToProxy.generated.h"

class AActor;
class APawn;
class UMercunaMoveToProxy;
class UObject;

UCLASS(Blueprintable, MinimalAPI)
class UMercunaMoveToProxy : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaNavigationResult OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaNavigationResult OnFailure;
    
    UMercunaMoveToProxy();
private:
    UFUNCTION(BlueprintCallable)
    void OnMoveComplete(FAIRequestID RequestID, TEnumAsByte<EMercunaMoveResult::Type> Result);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UMercunaMoveToProxy* MercunaMoveToLocations(UObject* WorldContextObject, UPARAM(Ref) APawn*& Pawn, const TArray<FVector>& Destinations, float EndDistance, float Speed, bool UsePartialPath);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UMercunaMoveToProxy* MercunaMoveToLocation(UObject* WorldContextObject, APawn* Pawn, const FVector& Destination, float EndDistance, float Speed, bool UsePartialPath);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UMercunaMoveToProxy* MercunaMoveToActor(UObject* WorldContextObject, APawn* Pawn, AActor* Actor, float EndDistance, float Speed, bool UsePartialPath);
    
};

