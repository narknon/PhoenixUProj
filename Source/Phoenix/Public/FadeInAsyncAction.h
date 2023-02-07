#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FadeOutputPinDelegate.h"
#include "FadeInAsyncAction.generated.h"

class UFadeInAsyncAction;

UCLASS(Blueprintable)
class UFadeInAsyncAction : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFadeOutputPin Complete;
    
public:
    UFadeInAsyncAction();
protected:
    UFUNCTION(BlueprintCallable)
    void OnFadeComplete();
    
public:
    UFUNCTION(BlueprintCallable)
    static UFadeInAsyncAction* FadeIn(const float Duration);
    
};

