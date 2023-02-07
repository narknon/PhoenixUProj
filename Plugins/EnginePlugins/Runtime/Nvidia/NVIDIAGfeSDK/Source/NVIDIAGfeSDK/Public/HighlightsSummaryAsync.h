#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GfeSDKHighlightSummaryParams.h"
#include "OnHighlightsOperationResultCallbackDelegate.h"
#include "HighlightsSummaryAsync.generated.h"

class UHighlightsSummaryAsync;
class UObject;

UCLASS(Blueprintable)
class NVIDIAGFESDK_API UHighlightsSummaryAsync : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnFailure;
    
    UHighlightsSummaryAsync();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UHighlightsSummaryAsync* HighlightsOpenSummary(UObject* WorldContextObject, const FGfeSDKHighlightSummaryParams& Params);
    
};

