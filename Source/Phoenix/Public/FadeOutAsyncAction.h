#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FadeOutputPinDelegate.h"
#include "FadeOutAsyncAction.generated.h"

class UFadeOutAsyncAction;

UCLASS(Blueprintable)
class UFadeOutAsyncAction : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFadeOutputPin Complete;
    
public:
    UFadeOutAsyncAction();
protected:
    UFUNCTION(BlueprintCallable)
    void OnFadeComplete();
    
public:
    UFUNCTION(BlueprintCallable)
    static UFadeOutAsyncAction* FadeOut(const float Duration);
    
};

