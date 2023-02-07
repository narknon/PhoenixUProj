#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "EGfeSDKHighlightSignificance.h"
#include "EGfeSDKHighlightType.h"
#include "OnGetNumberOfHighlightsCallbackDelegate.h"
#include "OnHighlightsOperationResultCallbackDelegate.h"
#include "HighlightsGetNumberAsync.generated.h"

class UHighlightsGetNumberAsync;
class UObject;

UCLASS(Blueprintable)
class NVIDIAGFESDK_API UHighlightsGetNumberAsync : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGetNumberOfHighlightsCallback OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnFailure;
    
    UHighlightsGetNumberAsync();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UHighlightsGetNumberAsync* HighlightsGetNumberOfHighlights(UObject* WorldContextObject, const FString& GroupId, const EGfeSDKHighlightType& TagFilter, const EGfeSDKHighlightSignificance& SignificanceFilter);
    
};

