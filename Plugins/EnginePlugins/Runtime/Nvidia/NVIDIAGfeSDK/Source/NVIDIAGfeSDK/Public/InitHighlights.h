#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OnHighlightsInitCallbackDelegate.h"
#include "OnHighlightsOperationResultCallbackDelegate.h"
#include "InitHighlights.generated.h"

class UInitHighlights;
class UObject;

UCLASS(Blueprintable)
class NVIDIAGFESDK_API UInitHighlights : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsInitCallback OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnFailure;
    
    UInitHighlights();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UInitHighlights* InitHighlights(UObject* WorldContextObject, const FString& InGameName, const bool Video, const bool Screenshots);
    
};

