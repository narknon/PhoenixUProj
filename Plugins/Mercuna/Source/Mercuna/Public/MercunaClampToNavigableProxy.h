#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MercunaClampToNavigableResultDelegate.h"
#include "MercunaClampToNavigableProxy.generated.h"

class UMercunaClampToNavigableProxy;
class UObject;

UCLASS(Blueprintable, MinimalAPI)
class UMercunaClampToNavigableProxy : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaClampToNavigableResult OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaClampToNavigableResult OnFailure;
    
    UMercunaClampToNavigableProxy();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UMercunaClampToNavigableProxy* MercunaClampToNavigable(UObject* WorldContextObject, FVector Position, float NavigationRadius, float SearchRadius);
    
};

