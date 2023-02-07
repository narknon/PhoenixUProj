#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MercunaRaycastResultDelegate.h"
#include "MercunaRaycastProxy.generated.h"

class UMercunaRaycastProxy;
class UObject;

UCLASS(Blueprintable, MinimalAPI)
class UMercunaRaycastProxy : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaRaycastResult OnHit;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaRaycastResult OnNoHit;
    
    UMercunaRaycastProxy();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UMercunaRaycastProxy* MercunaRaycast(UObject* WorldContextObject, FVector Start, FVector End, float NavigationRadius);
    
};

