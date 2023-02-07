#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OnHighlightsOperationResultCallbackDelegate.h"
#include "RequestPermissionsAsync.generated.h"

class UObject;
class URequestPermissionsAsync;

UCLASS(Blueprintable)
class NVIDIAGFESDK_API URequestPermissionsAsync : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnFailure;
    
    URequestPermissionsAsync();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static URequestPermissionsAsync* GFERequestPermissions(UObject* WorldContextObject, const bool Video, const bool Screenshots);
    
};

