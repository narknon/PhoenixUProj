#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GfeSDKHighlightOpenGroupParams.h"
#include "OnHighlightsOperationResultCallbackDelegate.h"
#include "HighlightsOpenGroupAsync.generated.h"

class UHighlightsOpenGroupAsync;
class UObject;

UCLASS(Blueprintable)
class NVIDIAGFESDK_API UHighlightsOpenGroupAsync : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnFailure;
    
    UHighlightsOpenGroupAsync();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UHighlightsOpenGroupAsync* HighlightsOpenGroup(UObject* WorldContextObject, const FGfeSDKHighlightOpenGroupParams& Params);
    
};

