#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AkExternalSourceInfo.h"
#include "OnAkPostEventCallbackDelegate.h"
#include "PostEventAsyncOutputPinDelegate.h"
#include "PostEventAsync.generated.h"

class AActor;
class UAkAudioEvent;
class UObject;
class UPostEventAsync;

UCLASS(Blueprintable)
class AKAUDIO_API UPostEventAsync : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostEventAsyncOutputPin Completed;
    
    UPostEventAsync();
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
    static UPostEventAsync* PostEventAsync(const UObject* WorldContextObject, UAkAudioEvent* AkEvent, AActor* Actor, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources, bool bStopWhenAttachedToDestroyed);
    
private:
    UFUNCTION(BlueprintCallable)
    void PollPostEventFuture();
    
};

